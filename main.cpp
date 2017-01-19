#include <iostream>
#include <string>
#include "utils.h"
#include <vector>
#include "algorithm.h"
#include "fifo_algorithm.h"
#include "random_algorithm.h"
#include <fstream>

#define FIFO_ALGO "fifo"
#define RANDOM_ALGO "random"

using namespace std;

typedef long long ll;
int main(int argc, char *argv[]) {

	if(argc < 9) {
		return -1;
	}

	string algorithm_str(argv[2]);
	string file_name(argv[4]);
	string num_of_frames(argv[6]);
	string page_size_str(argv[8]);


	vector< pair<long long, int> > references;
	get_memory_references(file_name, references);

	int page_size = get_page_size(page_size_str);

	// ifstream fin(file_name.c_str());


	int number_of_pages = needed_pages(1024, references);

	int number_of_frames = get_number_of_frames(number_of_pages, num_of_frames);

	Algorithm *algo;

	if (algorithm_str == FIFO_ALGO)
		algo = new fifo_algorithm(number_of_frames, page_size);
	else if (algorithm_str == RANDOM_ALGO)
		algo = new random_algorithm(number_of_frames, page_size);

	for(int i = 0; i < references.size(); ++i)
		algo->access(references[i].first, references[i].second);

	cout << "Total number of memory references: " << references.size() << endl;
	cout << "Number of pages: " << number_of_pages << endl;
	cout << "Number of frames: " << number_of_frames << endl;

	cout << "Number of page faults: " << algo->get_number_of_page_faults() << endl;
}