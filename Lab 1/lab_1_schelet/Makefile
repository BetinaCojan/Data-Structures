.PHONY: build debug run clean

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = $(wildcard *.cpp)
ELFS = $(patsubst %.cpp, %, $(SRCS))

build: $(ELFS)

set_dbg: CFLAGS += -DDEBUG

debug: set_dbg

set_dbg: build

%: %.cpp
	$(CC) $(CFLAGS) -o $@ $^

run:
	for ELF in $(ELFS); do \
    ./$$ELF; \
  done

clean:
	rm -f $(ELFS)
