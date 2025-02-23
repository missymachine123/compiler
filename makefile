# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Files
OBJS = main.o lex.yy.o k0gram.tab.o

# Targets
all: my_program

my_program: $(OBJS)
	$(CC) $(CFLAGS) -DYYDEBUG -o k0 $(OBJS) -lfl

main.o: main.c k0gram.tab.h tree.h
	$(CC) $(CFLAGS) -c main.c

lex.yy.o: lex.yy.c k0gram.tab.h tree.h
	$(CC) $(CFLAGS) -c lex.yy.c

k0gram.tab.o: k0gram.tab.c tree.h
	$(CC) $(CFLAGS) -c k0gram.tab.c

k0gram.tab.c k0gram.tab.h: k0gram.y
	bison -d k0gram.y

lex.yy.c: k0lex.l k0gram.tab.h tree.h

	flex k0lex.l

clean:
	rm -f $(OBJS) k0 lex.yy.c k0gram.tab.c k0gram.tab.h

.PHONY: clean
