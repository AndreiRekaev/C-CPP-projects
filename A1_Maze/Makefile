CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g
PROJECT := Maze
PROJECT_DIR := ${PROJECT}/
TEST_DIR := tests

MODEL := $(shell find ${PROJECT_DIR}model -type f -name "*.cc") 
CONTROLLER := $(shell find ${PROJECT_DIR}controller -type f -name "*.cc")
SRC := ${MODEL} ${CONTROLLER} ${PROJECT_DIR}view/cave/gen/gencave.cc
OBJ := $(patsubst %.cc, %.o, ${SRC})
SRC_TEST := $(shell find ${TEST_DIR} -type f -name "*.cc")
OBJ_TEST := $(patsubst %.cc, %.o, ${SRC_TEST})


LDFLAGS= -lgtest -lgmock
NAME := $(shell uname -s)
ifeq (${NAME}, Linux) 
		LDFLAGS= ${LDFLAGS} -lpthread
endif

.PHONY: all clean test build  

all: clean install

e: 
		@echo ${OBJ}
		@echo ${OBJ_TEST}
install: 
		
uninstall:
		

clean:
		@rm -rf $(shell find ${PROJECT} -type f -name "*.o")
		@rm -rf test build 
		
	
dvi:
		
		
dist:

			
test: ${OBJ} ${OBJ_TEST}
		${CXX} $^ ${LDFLAGS} -o $@
		./test
%.o: %.cc %.h
		${CXX} ${CXXFLAGS} -c ${filter-out %.h, $^} -o $@
				
start: 
		open ${PROJECT_DIR}CMakeLists.txt -a "Qt Creator.app"
check: 
		@cp ../materials/linters/.clang-format ./
		clang-format -n $(shell find ${PROJECT} tests -type f -name "*.cc" -o -name "*.h")
		@rm -rf .clang-format
check2:
		@cp ../materials/linters/.clang-format ./
		clang-format -i $(shell find ${PROJECT} tests -type f -name "*.cc" -o -name "*.h")
		@rm -rf .clang-format
