CC = gcc
FLAGS = -c -Wall -Werror
FLAGS_1 = -I thirdparty -I src -c
EXE = bin/string
EXE_TEST = bin/string_test

.PHONY: all clean

all: $(EXE) $(EXE_TEST)

$(EXE): build/src/main.o build/src/function.o build/src/strings.o
	$(CC) build/src/main.o build/src/function.o build/src/strings.o -o $@

build/src/main.o: src/main.c
	$(CC) $(FLAGS) src/main.c -o $@

build/src/function.o: src/function.c
	$(CC) $(FLAGS) src/function.c -o $@

build/src/strings.o: src/strings.c
	$(CC) $(FLAGS) src/strings.c -o $@

$(EXE_TEST): build/test/main.o build/test/function_test.o build/src/function.o build/src/strings.o
	$(CC) build/test/main.o build/test/function_test.o build/src/function.o build/src/strings.o -o $@

build/test/main.o: test/main.c
	$(CC) -I thirdparty -c test/main.c -o $@

build/test/function_test.o: test/function_test.c
	$(CC) $(FLAGS_1) test/function_test.c -o $@

clean:
	rm -f bin/*
	rm -f build/src/*.o
	rm -f build/test/*.o