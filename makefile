CC = g++
CFLAGS = -g -Wall -std=c++17
DEPS = fibonacci_word.h
OBJ = main_fibonacci_word.o fibonacci_word.o
EXEC = fibonacci_words

all: $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXEC) $^

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $<


.PHONY: clean

clean:
	 bash -O extglob -c "rm -vf !(*.cc|*.h|"makefile"|input.txt)"
