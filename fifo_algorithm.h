#ifndef FIFO_H
#define FIFO_H 1

#include "algorithm.h"
#include <list>

class fifo_algorithm : public Algorithm
{
public:
	fifo_algorithm(int number_of_frames, int page_size);
protected:
	std::list<long long> pages;
	void _access(long long address);
};

#endif