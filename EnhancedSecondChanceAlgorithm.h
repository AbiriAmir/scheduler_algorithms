#ifndef ENHANCED_SECOND_CHANCE_H
#define ENHANCED_SECOND_CHANCE_H 1

#include "Algorithm.h"
#include "PageEntity.h"
#include <list>
#include <cstring>


class EnhancedSecondChanceAlgorithm : public Algorithm {
public:
	EnhancedSecondChanceAlgorithm(int number_of_frames, int page_size);
protected:
	std::list<PageEntity> pages;
	std::list<PageEntity>::iterator pointer;
	void _access(long long page, MemoryReference::AccessType access_type);
};

#endif