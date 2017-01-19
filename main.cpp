#include <iostream>
#include <string>
#include "utils.h"
#include <vector>
#include "Algorithm.h"
#include "FifoAlgorithm.h"
#include "RandomAlgorithm.h"
#include <fstream>

#define FIFO_ALGO "fifo"
#define RANDOM_ALGO "random"

#define DEFAULT_FILE_NAME "pinatrace.out"
#define DEFAULT_NUMBER_OF_FRAMES "10%"
#define DEFAULT_PAGE_SIZE "4k"

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {

	if(argc < 9) {
		return -1;
	}

	string algorithm_str = FIFO_ALGO; // (argv[2]);
	string file_name = DEFAULT_FILE_NAME; // (argv[4]);
	string num_of_frames = DEFAULT_NUMBER_OF_FRAMES; // (argv[6]);
	string page_size_str = DEFAULT_PAGE_SIZE; //(argv[8]);

	for(int i = 0; i < argc - 1; ++i) {
		string 
			tmp(argv[i]),
			tmp2(argv[i+1]);

		if(tmp == "--algorithm")
			algorithm_str = tmp2;

		if(tmp == "--trace")
			file_name = tmp2;

		if(tmp == "--pages")
			num_of_frames = tmp2;

		if(tmp == "--page_size")
			page_size_str = tmp2;
	}


	vector< pair<long long, int> > references;
	get_memory_references(file_name, references);

	int page_size = get_page_size(page_size_str);

	// ifstream fin(file_name.c_str());


	int number_of_pages = needed_pages(1024, references);

	int number_of_frames = get_number_of_frames(number_of_pages, num_of_frames);

	Algorithm *algo;

	if (algorithm_str == FIFO_ALGO)
		algo = new FifoAlgorithm(number_of_frames, page_size);
	else if (algorithm_str == RANDOM_ALGO)
		algo = new RandomAlgorithm(number_of_frames, page_size);

	for(int i = 0; i < references.size(); ++i)
		algo->access(references[i].first, references[i].second);

	cout << "Total number of memory references: " << references.size() << endl;
	cout << "Number of pages: " << number_of_pages << endl;
	cout << "Number of frames: " << number_of_frames << endl;

	cout << "Number of page faults: " << algo->get_number_of_page_faults() << endl;
}