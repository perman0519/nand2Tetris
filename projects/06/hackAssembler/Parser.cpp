//
// Created by 송준상 on 2/15/24.
//

#include <iostream>
#include "Parser.hpp"

Parser::Parser(std::string asmFile) : inputFile(asmFile) {
//	this->inputFile.open(asmFile, std::ifstream::in);

//	this->inputFile = std::ifstream(asmFile, std::ifstream::in);
}

Parser::~Parser() {
	inputFile.close();
};

bool Parser::hasMoreLines() {
	if (inputFile.eof())
		return false;
	else
		return true;
}

void Parser::advance() {
	std::string tmp;

	this->nowLine.clear();
	std::getline(this->inputFile, tmp, '\r');
	this->inputFile.ignore(1, '\r');
//	this->inputFile.ignore(1, '\n');
	for (size_t i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] != ' ')
			this->nowLine.append(1, tmp[i]);
	}
	while ((this->nowLine.compare(0, 2, "//") || this->nowLine.length() == 0) &&
			!this->inputFile.eof())
	{
		std::getline(this->inputFile, tmp);
//		this->inputFile.ignore(1, '\n');
		for (size_t i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] != ' ')
				this->nowLine.append(1, tmp[i]);
		}
	}
}

instrucType Parser::instructionType() {
	if (this->nowLine.find("//") != std::string::npos)
		this->nowLine = this->nowLine.substr(0, this->nowLine.find("//"));

	if (this->nowLine.find('@') != std::string::npos)
		return instrucType::A_INSTRUC;
	else if (this->nowLine.find('(') == 0 &&
			this->nowLine.find(')') == this->nowLine.length())
		return instrucType::L_INSTRUC;
	else if (this->nowLine.length() != 0)
		return instrucType::C_INSTRUC;
	else
		return instrucType::ELSE;
}

std::string Parser::symbol() {
	if (instructionType() == instrucType::A_INSTRUC)
		return this->nowLine.substr(1, this->nowLine.length());
	else
		return this->nowLine.substr(1, this->nowLine.length() - 1);
}

std::string Parser::dest() {
	if (this->nowLine.find('=') == std::string::npos)
		return NULL;
	else
		return this->nowLine.substr(0, this->nowLine.find('='));
}

std::string Parser::comp() {
	if (this->nowLine.find('=') == std::string::npos && this->nowLine.find(';') == std::string::npos)
		return "";
	else if (this->nowLine.find('=') == std::string::npos && this->nowLine.find(';') == std::string::npos)
		return this->nowLine.substr(0, this->nowLine.find(';'));
	else
		return this->nowLine.substr(this->nowLine.find('=') + 1,this->nowLine.length());
}

std::string Parser::jump() {
	if (this->nowLine.find(';') == std::string::npos)
		return NULL;
	else
		return this->nowLine.substr(this->nowLine.find(';') + 1, \
			this->nowLine.length());
}
