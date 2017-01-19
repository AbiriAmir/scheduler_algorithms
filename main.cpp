#include <iostream>
#include <string>
#include "utils.h"
#include <vector>

using namespace std;

typedef long long ll;
int main(int argc, char *argv[]) {

	if(argc < 9) {
		return -1;
	}

	string algo(argv[2]);
	string file_name(argv[4]);
	string num_of_frames(argv[6]);
	string page_size_str(argv[8]);

	int page_size = get_page_size(page_size_str);

	// ifstream fin(file_name.c_str());


	int number_of_pages = needed_pages(file_name, 1024);

	int number_of_frames = get_number_of_frames(number_of_pages, num_of_frames);
}