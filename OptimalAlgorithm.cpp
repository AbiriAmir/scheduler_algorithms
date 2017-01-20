#include "OptimalAlgorithm.h"
#include <iostream>
#include <set>

using namespace std;

OptimalAlgorithm::OptimalAlgorithm(int number_of_frames, int page_size, vector< pair<long long, int> > &_references) : 
	Algorithm(number_of_frames, page_size) {
	// references = _references;
	for(int i = 0; i < _references.size(); ++i)
		references.push_back(_references[i]);
}


int OptimalAlgorithm::find_victim() {

	set<long long> s;

	for(int i = 0; i < this->pages.size(); ++i) {
		// cerr << pages[i] << " -> s \n";
		s.insert(pages[i]);
	}

	for(list< pair<long long, int> >::iterator i = references.begin(); i != references.end() && s.size() > 1; ++i) {
		for(int j = 0; j < (*i).second && s.size() > 1; ++j) {
			// cerr << "erasing " << ((*i).first + j) / page_size << endl;
			s.erase(((*i).first + j) / page_size);
		}
	}

	// cerr << s.size() << endl;
	// int index = 0 ;
	// for(int i = 0 ; i < pages.size() ; i++){
		// for(int j = 0 ; j < references.size(); j++){
			// for(int k = 0; k < references[j].second ; k++) {
				// if(pages[i] == (references[j].first + k) / page_size && i > index)
					// index = i;
			// }
		// }
		// if(index==0)
			// break;
	// }
	// cout<<index<<" ";
	
	for(int i = 0; i < pages.size(); ++i) {
		if(pages[i] == *(s.begin())) {
			// cerr << i << endl;
			return i;
		}
	} 
	return -1;
}

void OptimalAlgorithm::access(long long address, int bytes) {
	this->references.pop_front();
	Algorithm::access(address, bytes);
}


void OptimalAlgorithm::_access(long long page) {
	for(vector<long long>::iterator it = pages.begin(); it != pages.end(); ++it) {
		if(*it == page)
			return;
	}

	this->page_faults++;

	if(pages.size() >= this->number_of_frames) {
		int page_to_delete = find_victim();
		this->pages[page_to_delete] = page;
	} else {
		this->pages.push_back(page);
	}

	// cout << "Page size: " << pages.size() << endl;
	// for(int i = 0; i < pages.size(); ++i) 
		// cout << pages[i] << " ";
	// cout << endl;

}


