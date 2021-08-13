#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>

/*
 * USAGE :
 *
 * 1) Run this server
 * 2) Run telnet localhost 3000 on another terminal
 * 3) See the output printed on another terminal ofc
 *
 */

#define HANDLE_SEND_RECV_ERRORS(st)                                            \
  if ((st) == -1) {                                                            \
    printf("Error occured in send or recv\n");                                 \
    exit(254);                                                                 \
  } else if ((st) == 0) {                                                      \
    printf("Connection is closed because send/recv returned 0\nError!!\n");    \
    exit(255);                                                                 \
  }

int get_port(const sockaddr_storage *addr) {
  if (addr->ss_family == AF_INET) {
    return ((struct sockaddr_in *)addr)->sin_port;
  } else {
    return ((struct sockaddr_in6 *)addr)->sin6_port;
  }
}

void *get_in_addr(const sockaddr_storage *addr) {
  if (addr->ss_family == AF_INET) {
    return &((struct sockaddr_in *)addr)->sin_addr;
  } else {
    return &((struct sockaddr_in6 *)addr)->sin6_addr;
  }
}

void print_conn_name(int fd, const sockaddr_storage *addr) {
  char buf[1000];
  inet_ntop(addr->ss_family, get_in_addr(addr), buf, sizeof(sockaddr_storage));
  int port = get_port(addr);
  printf("Connected to %s at port %d\n", buf, port);
}

#define PORT "3000"
#define BACKLOG 100
#define BUF_SIZE 32

void handle_connection(int conn_fd) {
  char buf[32] = "HELLO friend!!!!\n";
  int status = send(conn_fd, buf, BUF_SIZE, 0);
  HANDLE_SEND_RECV_ERRORS(status);
  printf("Sent message successfully\n");
  close(conn_fd);
}

int main() {
  struct addrinfo hint, *res, *result;
  struct sockaddr_storage *addr;
  socklen_t len = sizeof(sockaddr_storage);
  int status;
  int fd;
  int yes = 1;

  memset(&hint, 0, sizeof(hint));
  hint.ai_family = AF_UNSPEC;
  hint.ai_socktype = SOCK_STREAM;
  hint.ai_flags = AI_PASSIVE;

  if ((status = getaddrinfo(NULL, PORT, &hint, &res)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    exit(1);
  }

  for (result = res; result != nullptr; result = result->ai_next) {
    fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (fd == -1)
      continue;

    // if the port is not available, it exits
    if ((status = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes,
                             sizeof(yes))) == -1) {
      perror("setsockopt");
      exit(2);
    }

    status = bind(fd, result->ai_addr, result->ai_addrlen);
    if (status == -1) {
      close(fd);
      perror("Bind failed");
      continue;
    }

    // we  found something that connects
    break;
  }
  // means we had error
  if (fd == -1 || status == -1) {
    fprintf(stderr, "Server failed to bind\n");
    exit(3);
  }
  /* Same thing as above i think
   * if(result==NULL)
   *   exit(3);
   */

  freeaddrinfo(res);

  listen(fd, BACKLOG);

  printf("Server started,Waiting for connnection....\n");

  while (1) {
    int conn = accept(fd, (struct sockaddr *)addr, &len);
    if (conn == -1) {
      perror("Error in accepting connection\n");
      continue;
    }
    print_conn_name(conn, addr);
    std::thread t(handle_connection, conn);
    t.detach();
  }
  return 0;
}
