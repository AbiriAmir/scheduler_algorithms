a.out: main.cpp utils.o Algorithm.o FifoAlgorithm.o RandomAlgorithm.o
	g++ main.cpp utils.o Algorithm.o FifoAlgorithm.o RandomAlgorithm.o

utils.o: utils.cpp
	g++ -c utils.cpp

Algorithm.o: Algorithm.cpp
	g++ -c Algorithm.cpp

FifoAlgorithm.o: FifoAlgorithm.cpp
	g++ -c FifoAlgorithm.cpp

RandomAlgorithm.o: RandomAlgorithm.cpp
	g++ -c RandomAlgorithm.cpp