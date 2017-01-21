a.out: main.cpp utils.o Algorithm.o FifoAlgorithm.o RandomAlgorithm.o LruAlgorithm.o SecondChanceAlgorithm.o PageEntity.o OptimalAlgorithm.o EnhancedSecondChanceAlgorithm.o MemoryReference.o
	g++ -O2 main.cpp utils.o Algorithm.o FifoAlgorithm.o RandomAlgorithm.o LruAlgorithm.o SecondChanceAlgorithm.o PageEntity.o OptimalAlgorithm.o EnhancedSecondChanceAlgorithm.o MemoryReference.o

utils.o: utils.cpp
	g++ -c utils.cpp

Algorithm.o: Algorithm.cpp
	g++ -c Algorithm.cpp

FifoAlgorithm.o: FifoAlgorithm.cpp
	g++ -c FifoAlgorithm.cpp

RandomAlgorithm.o: RandomAlgorithm.cpp
	g++ -c RandomAlgorithm.cpp

LruAlgorithm.o: LruAlgorithm.cpp
	g++ -c LruAlgorithm.cpp

PageEntity.o: PageEntity.cpp
	g++ -c PageEntity.cpp

SecondChanceAlgorithm.o: SecondChanceAlgorithm.cpp
	g++ -c SecondChanceAlgorithm.cpp

OptimalAlgorithm.o: OptimalAlgorithm.cpp
	g++ -c OptimalAlgorithm.cpp

EnhancedSecondChanceAlgorithm.o: EnhancedSecondChanceAlgorithm.cpp
	g++ -c EnhancedSecondChanceAlgorithm.cpp

MemoryReference.o: MemoryReference.cpp
	g++ -c MemoryReference.cpp
