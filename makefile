CC=g++
CFLAGS=-std=c++11
SOURCES=player1.cpp

all: game run

game: $(SOURCES)
	$(CC) -o game $(SOURCES) $(CFLAGS)

run:
	./game