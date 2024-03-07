# Copyright Florin-Cristian Motrun 334CA 2023-2024

# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# define targets
TARGETS = my_octave

# source files
SRCS=$(wildcard *.c) $(wildcard operations/*.c)
OBJS = $(SRCS:.c=.o)

build: $(TARGETS)

my_octave: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o my_octave

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

pack:
	zip -FSr 334CA_MotrunFlorin_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: pack clean
