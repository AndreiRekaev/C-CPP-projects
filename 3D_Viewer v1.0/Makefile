cc = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
SRC = 3DViewer/*.c
SRC_TEST = tests/*.c
OBJ = $(patsubst %.c, %.o, $(wildcard $(SRC)))
OBJ_TEST = $(patsubst %.c, %.o, $(wildcard $(SRC_TEST)))

.PHONY: all clean test build dist install
$(OBJ): 3DViewer/3DViewer.h
$(OBJ_TEST): tests/main.h
NAME := $(shell uname -s)

ifeq ($(NAME), Linux)
		LDFLAGS = -lcheck -lsubunit -lm -lrt -lpthread
else ifeq ($(NAME), Darwin)
		LDFLAGS = -lcheck
endif

all: clean build

build: 
		@- mkdir build
		cd build/ && cmake -DCMAKE_BUILD_TYPE=Release ../3DViewer/CMakeLists.txt
		cd build/ && make
		chmod 755 build/3DViewer.app
open:
		open ../../3DViewer/3DViewer.app/
install:
		@- mkdir ../../3DViewer
		cp -rf build/3DViewer.app ../../3DViewer/3DViewer.app
uninstall:
		rm -rf ../../3DViewer
dvi:
		-doxygen Doxyfile -w html 
		open html/index.html
dviclean:
		rm -rf html/ latex/

dist:
		tar cvf ../../3DViewer-1.0.tar 3DViewer/*.ui 3DViewer/*.h 3DViewer/*.c 3DViewer/*.cpp 3DViewer/*.txt 3DViewer/resources.qrc 3DViewer/pic.png 3DViewer/giflib/* ./Doxyfile ./description.h ./Makefile
distclean: 
		rm -rf ../../3DViewer-1.0.tar
start:
		open 3DViewer/CMakeLists.txt -a "Qt Creator.app"
test: $(OBJ_TEST) $(OBJ)
		$(cc) $^ $(LDFLAGS) -o $@
		@if [ -f tests/bad.txt ] ; then mv tests/bad.txt tests/bad.obj ; fi
		@if [ -f tests/point.txt ] ; then mv tests/point.txt tests/point.obj ; fi
		@if [ -f tests/point1.txt ] ; then mv tests/point1.txt tests/point1.obj ; fi
		@if [ -f tests/cube.txt ] ; then mv tests/cube.txt tests/cube.obj ; fi
		@if [ -f tests/cat.txt ] ; then mv tests/cat.txt tests/cat.obj ; fi
		@if [ -f tests/trumpet.txt ] ; then mv tests/trumpet.txt tests/trumpet.obj ; fi
		./test
san: clean add_coverage test
leak: clean test
		leaks -atExit -- ./test
leak_app: 
		leaks -atExit -- ./build/3DViewer.app/Contents/MacOS/3DViewer
val: clean test
		valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test 
%.o: %.c
		@$(cc) $(CFLAGS) -c $< -o $@
check:
		@cp ../materials/linters/.clang-format ./
		clang-format -n 3DViewer/*.c 3DViewer/*.h 3DViewer/*.cpp 3DViewer/giflib/*.c 3DViewer/giflib/*.h tests/*.c tests/*.h
		@rm -rf .clang-format
check2:
		@cp ../materials/linters/.clang-format ./
		clang-format -i 3DViewer/*.c 3DViewer/*.h 3DViewer/*.cpp 3DViewer/giflib/*.c 3DViewer/giflib/*.h tests/*.c tests/*.h
		@rm -rf .clang-format

clean:
		@rm -rf $(OBJ) $(OBJ_TEST)
		@rm -rf test test.dSYM
		@rm -rf a.out a.out* 
		@rm -rf *.info *.gcno *.gcda report
		@rm -rf tests/*.info tests/*.gcno tests/*.gcda tests/*.gch
		@rm -rf build/ b2/

gcov_report: clean 
		$(cc) $(CFLAGS) --coverage $(SRC_TEST) $(SRC) $(LDFLAGS) -o test
		./test
		mkdir report
		lcov -t "test" -o test.info -c -d . 
		genhtml -o report test.info
		open report/index.html
		rm -rf *.gcda *.gcno *.out

add_coverage:
	$(eval CFLAGS += -fsanitize=address)
	$(eval LDFLAGS +=	-fsanitize=address)

rebuild: clean test
