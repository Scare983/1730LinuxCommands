CC = g++
DEBUG = -g -O0 -pedantic-errors
CFLAGS = -Wall -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: cal ln ls mkdir

cal: cal.o 
	$(CC) $(LFLAGS) -o cal cal.o

cal.o: cal.cpp
	$(CC) $(CFLAGS) cal.cpp

ln: ln.o
	$(CC) $(LFLAGS) -o ln ln.o

ln.o: ln.cpp
	$(CC) $(CFLAGS) ln.cpp

ls: ls.o
	$(CC) $(LFLAGS) -o ls ls.o

ls.o: ls.cpp
	$(CC) $(CFLAGS) ls.cpp

mkdir: mkdir.o
	$(CC) $(LFLAGS) -o mkdir mkdir.o

mkdir.o: mkdir.cpp
	$(CC) $(CFLAGS) mkdir.cpp

.PHONY: clean


clean:
	rm -rf *.o
	rm -rf cal
	rm -rf ln
	rm -rf ls
	rm -rf mkdir
