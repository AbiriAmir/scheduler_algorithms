#include "fifo_algorithm.h"

using namespace std;

fifo_algorithm::fifo_algorithm(int number_of_frames, int page_size) : Algorithm(number_of_frames, page_size) {
	// this->pages.resize(number_of_frames, -1);
}

void fifo_algorithm::_access(long long page) {
	for(list<long long>::iterator it = pages.begin(); it != pages.end(); ++it) {
		if(*it == page)
			return;
	}

	this->page_faults++;

	if(pages.size() >= this->number_of_frames)
		this->pages.pop_front();

	this->pages.push_back(page);
}