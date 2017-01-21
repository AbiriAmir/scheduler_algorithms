#include "EnhancedSecondChanceAlgorithm.h"
#include <iostream>

using namespace std;

EnhancedSecondChanceAlgorithm::EnhancedSecondChanceAlgorithm(int number_of_frames, int page_size) : Algorithm(number_of_frames, page_size) {
	pointer = pages.end();
}

void EnhancedSecondChanceAlgorithm::_access(long long page, MemoryReference::AccessType access_type) {
	for(list<PageEntity>::iterator it = pages.begin(); it != pages.end(); ++it) {
		if(it->page() == page) {
			if (access_type == MemoryReference::WRITE) {
				it->set_modify_bit();
			}
			it->set_reference_bit();
			return;
		}
	}

	this->page_faults++;

	if (pages.size() == 0) {
		pages.push_back(PageEntity (page));
		pointer = pages.begin();
	} else {
		if(pages.size() >= number_of_frames) {
			while (pointer->reference_bit() | pointer->modify_bit()) {
				if (pointer->reference_bit()) {
					pointer->reset_reference_bit();
				} else {
					// writes page to disk!
					pointer->reset_modify_bit();
				}
				pointer++;
				if (pointer == pages.end())
					pointer = pages.begin();
			}
			*pointer = PageEntity(page);
		} else {
			pages.push_back(PageEntity(page));
		}
	}
}