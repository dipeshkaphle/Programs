all: main

CC=g++
CFLAGS=-std=c++2a -Wall -Werror -fsanitize=address

main: main.cpp LRU_CacheWithLL.cpp LRU_Cache.h LRU_CacheVector.cpp
	$(CC) $(CFLAGS) -o $@ $<
