# Минимальный Makefile
all: main

main: Source.cpp Bank.cpp Bank.h
	g++ -std=c++11 -Wall Source.cpp Bank.cpp -o main

clean:
	rm -f main

run: main
	./main

.PHONY: all clean run
