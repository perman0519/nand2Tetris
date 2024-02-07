#include "HackAssembler.h"

int main(int argc, char *argv[])
{
    std::string fileStr(argv[1]);
    std::fstream asmFile(fileStr, std::fstream::in);
    fileStr.erase(fileStr.end() - 4, fileStr.end());
    fileStr.append(".hack");
    std::ofstream hackFile(fileStr, std::fstream::out);
    while (!asmFile.eof())
    {
        std::string str;
        std::getline(asmFile, str);
        std::cout << check_str(str) << std::endl;
    }
    asmFile.close();
}

std::string aInst(const std::string str)
{
	std::string a = str;
	a = a.substr(1, a.size() - 1);
	int aNum = std::atoi(a.c_str());
	std::string ret = std::bitset<16>(aNum).to_string();
	return ret;
}

std::string cInst(const std::string str)
{
	std::string ret("111");
	std::string dest, comp, jump;
	int compPoint = str.find("=");
	int jumpPoint = str.find(";");
	if (compPoint != std::string::npos)
		dest = str.substr(0, compPoint);
	else if (jumpPoint != std::string::npos)
		dest = str.substr(0, jumpPoint);
	else
		dest = str.substr(0, str.size() - 1);
	if (compPoint != std::string::npos) {
		if (jumpPoint != std::string::npos)
			comp = str.substr(compPoint + 1, jumpPoint - compPoint);
		else
			comp = str.substr(compPoint + 1, jumpPoint - compPoint);
	}
	else
		comp = nullptr;
	if (jumpPoint != std::string::npos)
		jump = str.substr(jumpPoint + 1, 3);
	else
		jump = nullptr;
	std::cout << dest << std::endl << comp << std::endl << jump << std::endl;
	return ret;
}

std::string check_str(const std::string str)
{
	if (str == "\n" || str.find("//") == 0)
		return std::string("");
	else if (str[0] == '@')
		return aInst(str);
	else
		return cInst(str);
		//TODO: C-instruction
}
