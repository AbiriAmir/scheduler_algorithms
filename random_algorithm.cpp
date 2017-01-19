#include "random_algorithm.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

random_algorithm::random_algorithm(int number_of_frames, int page_size) : Algorithm(number_of_frames, page_size) {
	srand(time(0));
}

void random_algorithm::_access(long long page) {
	for(vector<long long>::iterator it = pages.begin(); it != pages.end(); ++it) {
		if(*it == page)
			return;
	}

	this->page_faults++;

	if(pages.size() >= this->number_of_frames) {
		int page_to_delete = rand() % pages.size();
		this->pages.erase(this->pages.begin() + page_to_delete);
	}

	this->pages.push_back(page);
}