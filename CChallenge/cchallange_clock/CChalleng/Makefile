CC=clang
CFLAGS = -Wall -Werror -O3 -Wno-pragma-pack -I SDL2-2.0.9\include
LDFLAGS = -lSDL2 -L.

all: cchalleng.exe

cchalleng.exe: main.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $^