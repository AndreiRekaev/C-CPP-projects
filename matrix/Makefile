CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -std=c11
TEST_FLAGS		= -lm -lcheck -lpthread
GCOV_FLAGS		= -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS	= --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med #--track-fds=yes --show-leak-kinds=all
CHECK_FLAGS 	= $(shell pkg-config --cflags --libs check)
OS				= $(shell uname -s)
LIBRARY			= s21_matrix.a
SRC_PROJECT		= $(wildcard *.c)
SRC_TEST		= $(wildcard tests/*.c)
OBJ_PROJECT		= s21_create_matrix.o s21_remove_matrix.o s21_eq_matrix.o s21_sum_matrix.o s21_sub_matrix.o s21_mult_number.o s21_mult_matrix.o s21_transpose.o s21_calc_complements.o s21_determinant.o s21_inverse_matrix.o
OBJ_TEST		= test_s21_create_matrix.o test_s21_eq_matrix.o test_s21_sum_matrix.o test_s21_sub_matrix.o test_s21_mult_number.o test_s21_mult_matrix.o test_s21_transpose.o test_s21_calc_complements.o test_s21_determinant.o test_s21_inverse_matrix.o test.o

all: s21_matrix.a

s21_matrix.a: s21_matrix.o
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	ranlib $(LIBRARY)

s21_matrix.o:
	$(CC) $(CFLAGS) -c $(SRC_PROJECT)

test: clean s21_matrix.a test.o
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(CHECK_FLAGS)
	./test

test.o:
	$(CC) -c $(SRC_TEST)

gcov_report: clean test.o
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(CHECK_FLAGS) $(TEST_FLAGS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	make open

clean:
	rm -rf test
	rm -rf test_f
	rm -rf *.o
	rm -rf *.out
	rm -rf *.a
	rm -rf *.gcda
	rm -rf report
	rm -rf *.gcno
	rm -rf *.info
	rm -rf valgrind.txt
	rm -rf *.dSYM

rebuild: clean all

open: 
	open report/index.html

.PHONY: all clean rebuild open clang leaks_check docker cpp_check style_test sanitize

leaks_check: clean test
ifeq ($(OS), Linux)	
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"
else
	leaks -atExit -- ./test
endif

sanitize: clean
	$(CC) $(CFLAGS) -fsanitize=address -c $(SRC_PROJECT)
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	$(CC) $(CFLAGS) -fsanitize=address $(SRC_TEST) $(LIBRARY) -L. -lcheck -lm -o test_f
	./test_f

cpp_check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h

style_test: clang
	clang-format --style=google -n *.c

clang:
	clang-format --style=google -i *.c
	clang-format --style=google -i *.h
	clang-format --style=google -i tests/*

docker:
	cd ../materials/build; sh run.sh; cd ../../src