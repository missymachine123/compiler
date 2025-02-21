CC = gcc
CFLAGS = -Wall
LFLAGS = -lfl
LEX = flex

all: k0

k0: main.o lex.yy.o
	$(CC) $(CFLAGS) main.o lex.yy.o -o k0 $(LFLAGS)

lex.yy.c: k0lex.l
	$(LEX) k0lex.l 

main.o: main.c token.h
	$(CC) $(CFLAGS) -c main.c 

lex.yy.o: lex.yy.c token.h
	$(CC) $(CFLAGS) -c lex.yy.c $(LFLAGS)

clean:
	rm -f k0 lex.yy.c *.o