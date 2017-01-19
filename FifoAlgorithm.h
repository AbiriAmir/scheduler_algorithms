#ifndef FIFO_H
#define FIFO_H 1

#include "Algorithm.h"
#include <list>

class FifoAlgorithm : public Algorithm
{
public:
	FifoAlgorithm(int number_of_frames, int page_size);
protected:
	std::list<long long> pages;
	void _access(long long address);
};

#endif