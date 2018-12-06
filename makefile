final: main.o hash.o 
	g++ -o plagiarismCatcher main.o hash.o
main.o: main.cpp hash.h
	g++ -c main.cpp
hash.o: hash.h 
	g++ -c hash.cpp

