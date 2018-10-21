#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

//!< read the binary tree file
std::vector<int> parse_from( std::ifstream &ifs );

std::vector<std::pair<std::string, int>> parse_commands( std::ifstream &ifs );

#endif
