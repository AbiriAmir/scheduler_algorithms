#ifndef OPTIMAL_H
#define OPTIMAL_H 1

#include "Algorithm.h"
#include <list>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>

class OptimalAlgorithm : public Algorithm {
public:
	OptimalAlgorithm(int number_of_frames, int page_size, std::vector< std::pair<long long, int> > &references);
	void access(long long address, int bytes = 1);
protected:
	std::vector<long long> pages;
	std::list< std::pair<long long, int> > references;
	
	void _access(long long address);

	int find_victim();
};

#endif