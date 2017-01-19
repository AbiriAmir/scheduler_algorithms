#ifndef ALGORITHM_H
#define ALGORITHM_H 1

#include <vector>

class Algorithm {
public:
	Algorithm(int number_of_frames, int page_size);
	virtual void access(long long address, int bytes = 1);
	int get_number_of_page_faults();

protected:

	virtual void _access(long long address) = 0;

	int number_of_frames;
	int page_size;
	int page_faults;
};

#endif