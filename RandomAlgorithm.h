#ifndef RANDOM_H
#define RANDOM_H 1

#include "Algorithm.h"
#include <vector>

class RandomAlgorithm : public Algorithm
{
public:
	RandomAlgorithm(int number_of_frames, int page_size);
protected:
	std::vector<long long> pages;	
	void _access(long long page);
};

#endif