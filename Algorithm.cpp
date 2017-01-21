#include "Algorithm.h"
#include "MemoryReference.h"

Algorithm::Algorithm(int number_of_frames, int page_size) {
	this->number_of_frames = number_of_frames;
	this->page_size = page_size;
	this->page_faults = 0;
}

int Algorithm::get_number_of_page_faults() {
	return page_faults;
}

void Algorithm::access(MemoryReference memoryReference) {
	long long page;
	for(int i = 0; i < memoryReference.bytes; ++i) {
		page = (memoryReference.address + i) / page_size;
		this->_access(page, memoryReference.accessType);
	}
}