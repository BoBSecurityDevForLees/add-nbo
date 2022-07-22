#Makefile

all: add-nbo

add-nbo: main.o add.o
	g++ -o add-nbo main.o add.o

main.o: add.h main.cpp

add.o: add.h add.cpp

clean:
	rm -f add-nbo
	rm -f *.o
