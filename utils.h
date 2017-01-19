#ifndef UTILS
#define UTILS

#include <string>
#include <vector>

void split(const std::string &s, char delim, std::vector<std::string> &elems);


std::vector<std::string> split(const std::string &s, char delim);

long long hex2l(std::string s);

int needed_pages(std::string file_name, int page_size);

static inline std::string &ltrim(std::string &s);

// trim from end
static inline std::string &rtrim(std::string &s);

// trim from both ends
static inline std::string &trim(std::string &s);

int get_page_size(std::string s);

int get_number_of_frames(int number_of_pages, std::string num_of_frames);

#endif