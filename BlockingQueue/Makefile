TARGET = test
CXX = g++
CXXFLAGS = -g -O2 -Wall -Werror -std=c++11
LDFLAGS = -pthread
LIBS =

SOURCES = $(wildcard *.c *.cpp)

OBJS = $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCES)))

all: ${TARGET} ctags

${TARGET}: ${OBJS}
	${CXX} ${LDFLAGS} -o $@ $^ ${LIBS}

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< 

ctags:
	-ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .

.PHONY: all clean

clean:
	-rm -f *~ *.o *.swp tags ${TARGET}
