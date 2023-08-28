CC=g++
CFLAGS=-std=c++11
SOURCES=player1.cpp train.cpp dice.cpp unit.cpp print_units.cpp map.cpp

all: game run

game: $(SOURCES)
	$(CC) -o game $(SOURCES) $(CFLAGS)

run:
	./game