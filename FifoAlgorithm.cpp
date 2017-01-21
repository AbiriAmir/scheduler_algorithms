#include "FifoAlgorithm.h"

using namespace std;

FifoAlgorithm::FifoAlgorithm(int number_of_frames, int page_size) : Algorithm(number_of_frames, page_size) {
	// this->pages.resize(number_of_frames, -1);
}

void FifoAlgorithm::_access(long long page, MemoryReference::AccessType accessType) {
	for(list<long long>::iterator it = pages.begin(); it != pages.end(); ++it) {
		if(*it == page)
			return;
	}

	this->page_faults++;

	if(pages.size() >= this->number_of_frames)
		this->pages.pop_front();

	this->pages.push_back(page);
}