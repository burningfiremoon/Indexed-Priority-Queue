all: IndexedPriorityQueue_Test

IndexedPriorityQueue_Test: IndexedPriorityQueue_Test.o
	g++ -Wall -o IndexedPriorityQueue_Test IndexedPriorityQueue_Test.o

IndexedPriorityQueue_Test.o: IndexedPriorityQueue_Test.cpp IndexedPriorityQueue.h
	g++ -Wall -o IndexedPriorityQueue_Test.o -c IndexedPriorityQueue_Test.cpp

clean:
	rm -f IndexedPriorityQueue_Test *.o