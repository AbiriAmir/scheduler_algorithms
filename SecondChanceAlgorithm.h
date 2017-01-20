#ifndef SECOND_CHANCE_H
#define SECOND_CHANCE_H 1

#include "Algorithm.h"
#include "PageEntity.h"
#include <list>
#include <cstring>

class SecondChanceAlgorithm : public Algorithm {
public:
	SecondChanceAlgorithm(int number_of_frames, int page_size);
protected:
	std::list<PageEntity> pages;
	std::list<PageEntity>::iterator pointer;
	void _access(long long address);
};

#endif