#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

//!< Reads file containing tree values.
std::vector<int> parse_from( std::ifstream &ifs );

//!< Reads file containing operations commands.
std::vector<std::pair<std::string, int>> parse_commands( std::ifstream &ifs );

#endif
