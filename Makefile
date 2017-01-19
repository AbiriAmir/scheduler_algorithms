a.out: main.cpp utils.o algorithm.o fifo_algorithm.o random_algorithm.o
	g++ main.cpp utils.o algorithm.o fifo_algorithm.o random_algorithm.o

utils.o: utils.cpp
	g++ -c utils.cpp

algorithm.o: algorithm.cpp
	g++ -c algorithm.cpp

fifo_algorithm.o: fifo_algorithm.cpp
	g++ -c fifo_algorithm.cpp

random_algorithm.o: random_algorithm.cpp
	g++ -c random_algorithm.cpp