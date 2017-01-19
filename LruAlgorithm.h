#ifndef LRU_H
#define LRU_H 1

#include "Algorithm.h"
#include <list>

class LruAlgorithm : public Algorithm
{
public:
	LruAlgorithm(int number_of_frames, int page_size);
protected:
	std::list< std::pair<long long, int> > pages;
	std::list< std::pair<long long, int> >::iterator getMin();
	void _access(long long page);
	int access_num;
};

#endif