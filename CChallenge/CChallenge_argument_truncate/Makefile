CC=D:\LLVM\bin\clang.exe 
CPPCHECK=D:\CPPCHECK\cppcheck.exe
CFLAGS=-Wall -Wno-pragma-pack  
BINARY=main
BINARY_TESTS=main_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

final: main.o utils_method.o
	$(CC) -o $(BINARY) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

utils_method.o: utils_method.c 
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^


tests.o: tests.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

main_tests: tests.o main.o
	$(CC) -o $(BINARY_TESTS) $^
	./$(BINARY_TESTS)


