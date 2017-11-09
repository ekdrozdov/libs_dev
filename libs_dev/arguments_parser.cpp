/**
* arguments_parser.h
* Purpose: parse arguments supplied from command line
*
* @author iain
* @author Edward Drozdov
* @version 1.0 09/11/17
*/

#include "arguments_parser.h"


InputParser::InputParser(int &argc, char **argv) {
	for (int i = 1; i < argc; ++i)
		this->tokens.push_back(std::string(argv[i]));
};


const std::string& InputParser::getCmdOption(const std::string &option) const {
	std::vector<std::string>::const_iterator itr;
	itr = std::find(this->tokens.begin(), this->tokens.end(), option);
	if (itr != this->tokens.end() && ++itr != this->tokens.end()) {
		return *itr;
	}
	static const std::string empty_string("");
	return empty_string;
}


bool InputParser::cmdOptionExists(const std::string &option) const {
	return std::find(this->tokens.begin(), this->tokens.end(), option)
		!= this->tokens.end();
}