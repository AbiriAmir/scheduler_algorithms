#include "utils.h"
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;


void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
    	if(trim(item) != "")
        	elems.push_back(item);
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

long long hex2l(string s) {
	long long ans = 0;
	long long p = 1;
	for(int i = s.length() - 1; i >= 0; --i) {
		if(s[i] == 'x')
			break;
		int k;

		if(s[i] <= '9' && s[i] >= '0')
			k = s[i] - '0';
		else if(s[i] >= 'a' && s[i] <= 'f')
			k = s[i] - 'a' + 10;
		else
			k = 0;

		ans += p * k;
		p *= 16;
	} 
	return ans;
}

static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

int needed_pages(string file_name, int page_size) {
	ifstream fin(file_name.c_str());

	set<long long> bytes;

	string s;
	while(getline(fin, s)) {
		if(trim(s)[0] == '#')
			continue;
		vector<string> tokens = split(s, ' ');
		long long addr = hex2l(tokens[2]);
		// bytes.push_back(addr / page_size);
		
		int count = atoi(tokens[3].c_str());
		// cout << tokens[3] << " : " << count << endl;

		for(int i = 0; i < count; ++i)
			bytes.insert((addr + count) / page_size);
	}

	return bytes.size();

	// sort(bytes.begin(), bytes.end());

	// vector<long long>::iterator it = std::unique (bytes.begin(), bytes.end());
	// return std::distance(bytes.begin(), it);
}

int get_page_size(string s) {
	string temp = s.substr(0, s.length() - 1);

	int ans = atoi(temp.c_str());

	if(s[ s.length() - 1] == 'k') 
		ans *= 1024;
	else
		ans *= 1024 * 1024;

	return ans;
}

int get_number_of_frames(int number_of_pages, string number_of_frames) {
	int ans;
	if(number_of_frames[ number_of_frames.length() - 1 ] == '%') {
		string tmp = number_of_frames.substr(0, number_of_frames.length() - 1);
		ans = atoi(tmp.c_str());
	} else
		ans = atoi(number_of_frames.c_str());

	return ans;
}