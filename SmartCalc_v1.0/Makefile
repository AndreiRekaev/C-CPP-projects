CFLAGS := -std=c11 -pedantic
CPPFLAGS := -Wall -Werror -Wextra
CC = gcc
GFLAGS = --coverage
TFLAGS = -lcheck
OBJECTS = *.o
SOURCES := SmartCalc/*.c

SOURCES_TEST := test_calculator.c

all: clean test

s21_smartcalc.a:
	@$(CC) $(CPPFLAGS) $(SOURCES) $(ASAN) -c
	@ar rcs s21_smartcalc.a $(OBJECTS)
	@rm *.o

test: s21_smartcalc.a
	@$(CC) $(CPPFLAGS) $(ASAN) $(GFLAGS) s21_smartcalc.a $(SOURCES_TEST) $(TFLAGS) $(VAR) -o $@
	@./$@

check:
	clang-format -n -style=Google $(SOURCES) $(SOURCES_TEST) SmartCalc/s21_smartcalc.h

leaks:
	CK_FORK=no leaks --atExit -- ./test

gcov_report: all
	@$(CC) $(CPPFLAGS) $(SOURCES) $(GFLAGS) $(ASAN) -c
	@ar rcs s21_smartcalc.a $(OBJECTS)
	@rm *.o
	@$(CC) $(CPPFLAGS) $(ASAN) $(GFLAGS) s21_smartcalc.a $(SOURCES_TEST) $(TFLAGS) $(VAR) -o test
	@./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

install:
	mkdir Build
	cmake SmartCalc -B Build
	cmake --build Build

uninstall:
	cd Build && make clean
	rm -rf Build/CMakeCache.txt Build/SmartCalc.app
	rm -r Build
dist:
	cd .. && tar -czf SRC_C7_SmartCalc_v1.0-0.tgz src

dist_clean:
	cd .. && rm SRC_C7_SmartCalc_v1.0-0.tgz

dvi: dvi_clean
	makeinfo user_guide.texi --html
	open ./user_guide/index.html

doxygen:
	open ./doc/html/index.html

dvi_clean:
	rm -rf user_guide

clean:
	rm -rf $(OBJECTS) s21_smartcalc.a test *.gcda *.gcno *.html *.css report/ user_guide/
