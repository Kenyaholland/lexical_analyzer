OBJS = main.o analyzer.o parser.o symbol.o
SOURCE = main.c analyzer.c parser.c symbol.c
HEADER = analyzer.h parser.h symbol.h

OUT = main
CC = gcc
FLAGS = -g -c -Wall

all: $(OBJS)
		$(CC) -g $(OBJS) -o $(OUT)
	
main.o: main.c
		$(CC) $(FLAGS) main.c
	
analyzer.o: analyzer.c
		$(CC) $(FLAGS) analyzer.c
		
parser.o: parser.c
		$(CC) $(FLAGS) parser.c
		
symbol.o: symbol.c
		$(CC) $(FLAGS) symbol.c

clean:
		rm -f $(OBJS) $(OUT)