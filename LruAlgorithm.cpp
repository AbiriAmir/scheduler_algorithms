#include "LruAlgorithm.h"
#include <climits>
#include <iostream>

using namespace std;

LruAlgorithm::LruAlgorithm(int number_of_frames, int page_size) : Algorithm(number_of_frames, page_size) {
	this->access_num = 0;
}

void LruAlgorithm::_access(long long page, MemoryReference::AccessType accessType) {
	for(list< pair<long long, int> >::iterator it = pages.begin(); it != pages.end(); ++it) {
		if((*it).first == page) {
			(*it).second = access_num++;
			return;
		}
	}


	this->page_faults++;


	if(pages.size() >= this->number_of_frames) {
		list< pair<long long, int> >::iterator it = this->getMin();	
		*it = make_pair(page, access_num++);
	} else
		pages.push_back(make_pair(page, access_num++));
}

list< pair<long long, int> >::iterator LruAlgorithm::getMin() {
	list< pair<long long, int> >::iterator ans = pages.begin();
	int minAccessNum = INT_MAX;

	for(list< pair<long long, int> >::iterator it = pages.begin(); it != pages.end(); ++it) {
		if((*it).second < minAccessNum) {
			ans = it;
			minAccessNum = (*it).second;
		}
	}

	return ans;
}