#ifndef ALGORITHM_H
#define ALGORITHM_H 1

#include <vector>
#include "MemoryReference.h"

class Algorithm {
public:
	Algorithm(int number_of_frames, int page_size);
	virtual void access(MemoryReference);
	int get_number_of_page_faults();

protected:

	virtual void _access(long long address, MemoryReference::AccessType) = 0;

	int number_of_frames;
	int page_size;
	int page_faults;
};

#endif