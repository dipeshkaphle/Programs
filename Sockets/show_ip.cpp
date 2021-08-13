#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << R"(Please enter an address as commandline argument\n
		Run as: ./show_ip www.google.com\n)";
    return 1;
  }
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_protocol = SOCK_STREAM;
  int status = getaddrinfo(argv[1], NULL, &hints, &res);
  if (status != 0) {
    cout << "Error: " << gai_strerror(status) << '\n';
    return 2;
  }
  char ip[INET6_ADDRSTRLEN + 10];
  memset(ip, 0, sizeof ip);
  auto res_og = res;
  for (; res != nullptr; res = res->ai_next) {
    if (res->ai_family == AF_INET) {
      auto ip4 = (struct sockaddr_in *)res->ai_addr;
      inet_ntop(res->ai_family, &(ip4->sin_addr), ip, sizeof(sockaddr_in));
    } else {
      auto ip6 = (struct sockaddr_in6 *)res->ai_addr;
      inet_ntop(res->ai_family, &(ip6->sin6_addr), ip, sizeof(sockaddr_in6));
    }
    cout << ip << '\n';
  }
  freeaddrinfo(res_og);
}
