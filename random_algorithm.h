#ifndef RANDOM_H
#define RANDOM_H 1

#include "algorithm.h"
#include <vector>

class random_algorithm : public Algorithm
{
public:
	random_algorithm(int number_of_frames, int page_size);
protected:
	std::vector<long long> pages;	
	void _access(long long address);
};

#endif