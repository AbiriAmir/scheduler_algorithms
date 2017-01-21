#ifndef UTILS
#define UTILS

#include <string>
#include <vector>
#include "MemoryReference.h"

void split(const std::string &s, char delim, std::vector<std::string> &elems);


std::vector<std::string> split(const std::string &s, char delim);

long long hex2l(std::string s);

int needed_pages(int page_size, const std::vector< MemoryReference > &references);

static inline std::string &ltrim(std::string &s);

// trim from end
static inline std::string &rtrim(std::string &s);

// trim from both ends
static inline std::string &trim(std::string &s);

int get_page_size(std::string s);

int get_number_of_frames(int number_of_pages, std::string num_of_frames);

void get_memory_references(std::string file_name, std::vector< MemoryReference > &references);

#endif