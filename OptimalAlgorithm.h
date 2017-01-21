#ifndef OPTIMAL_H
#define OPTIMAL_H 1

#include "Algorithm.h"
#include <list>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include "MemoryReference.h"

class OptimalAlgorithm : public Algorithm {
public:
	OptimalAlgorithm(int number_of_frames, int page_size, std::vector< MemoryReference > &references);
	void access(MemoryReference);
protected:
	std::vector<long long> pages;
	std::list< MemoryReference > references;
	
	void _access(long long page, MemoryReference::AccessType);

	int find_victim();
};

#endif