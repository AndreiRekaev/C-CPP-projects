CC = gcc
OS = $(shell uname -s)



CFLAGS = -c -Wall -Werror -Wextra -std=c11 -g
LFLAGS = -lm -lrt -lpthread

all: s21_grep

s21_grep: s21_grep.o
ifeq ($(OS), Linux)
	$(CC) $(LFLAGS) s21_grep.o -o s21_grep
else
	$(CC) s21_grep.o -o s21_grep
endif

s21_grep.o: s21_grep.c
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep.o

check:
ifeq ($(OS), Linux)
	valgrind --track-origins=yes --leak-check=full -s ./s21_grep -v len s21_grep.c
else
	leaks -atExit -- ./s21_grep len s21_grep.c | grep LEAK:
endif

test: 
	sh grep_test/my_test.sh

rebuild: clean all

clean:
	rm -rf *.o s21_grep test_grep/test_results test_grep/log*

.PHONY: all
		clean
		s21_grep