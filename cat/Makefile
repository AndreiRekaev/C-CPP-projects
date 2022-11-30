CC = gcc
OS = $(shell uname -s)
DIR_TEST_CAT = test_cat/

CFLAGS = -c -Wall -Werror -Wextra -std=c11
LFLAGS = -lm -lrt -lpthread

all: s21_cat

s21_cat: s21_cat.o
ifeq ($(OS), Linux)
	$(CC) $(LFLAGS) s21_cat.o -o s21_cat
else
	$(CC) s21_cat.o -o s21_cat
endif

s21_cat.o: s21_cat.c
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat.o

test:
	bash test_cat/test_func_cat.sh
	bash test_cat/my_test.sh

rebuild: clean all

clean:
	rm -rf *.o s21_cat $(DIR_TEST_CAT)s21_cat
	