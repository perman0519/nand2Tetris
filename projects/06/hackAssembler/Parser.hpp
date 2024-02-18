//
// Created by 송준상 on 2/15/24.
//

#ifndef HACKASSEMBLER_PARSER_HPP
# define HACKASSEMBLER_PARSER_HPP

# include <fstream>
# include <string>
# include "HackAssembler.hpp"

class Parser {
private:
	std::string		nowLine;
	std::ifstream	inputFile;

public:
	Parser(std::string asmFile);
	~Parser();
	bool 			hasMoreLines();
	void 			advance();
	instrucType	    instructionType();
	std::string		symbol();
	std::string		dest();
	std::string		comp();
	std::string		jump();
};


#endif //HACKASSEMBLER_PARSER_HPP
