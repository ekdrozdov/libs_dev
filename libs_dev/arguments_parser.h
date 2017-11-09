/**
* arguments_parser.h
* Purpose: parse arguments supplied from command line
*
* @author iain
* @author Edward Drozdov
* @version 1.0 09/11/17
*/

#pragma once
#include <string>
#include <vector>


class InputParser {
public:
	InputParser(int &argc, char **argv);
	/// @author iain
	const std::string& getCmdOption(const std::string &option) const;
	/// @author iain
	bool cmdOptionExists(const std::string &option) const;
private:
	std::vector <std::string> tokens;
};
