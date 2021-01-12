all: main

CC=g++
CFLAGS=-std=c++2a -Wall -Werror -fsanitize=address

main: main.cpp LRU_Cache.cpp LRU_Cache.h
	$(CC) $(CFLAGS) -o $@ $<
