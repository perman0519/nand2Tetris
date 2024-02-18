#include "Parser.hpp"
#include "Code.hpp"
#include "SymbolTable.hpp"
#include "HackAssembler.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

string  getFileName(string str)
{
    return (str.substr(0, str.find(".")));
}

bool   isNumber(string str)
{
    for (unsigned long i = 0; i < str.size(); i++)
    {
        if (!('0' <= str.at(i) && str.at(i) <= '9'))
            return (false);
    }
    return (true);
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        string      fileName = getFileName(av[1]);
        Parser      first(av[1]);
        Parser      second(av[1]);
        SymbolTable sTable;
        Code        code;
        ofstream    outfile(fileName.append(".hack"));
        int         lineCount = 0;

        while (first.hasMoreLines())
        {
            first.advance();
            if (first.instructionType() == L_INSTRUC)
                sTable.addEntry(first.symbol(), lineCount + 1);
            else
                lineCount++;
        }
        lineCount = 16;
        while (second.hasMoreLines())
        {
            second.advance();
            if (second.instructionType() == A_INSTRUC)
            {
                if (isNumber(second.symbol()))
                    outfile << "0" << atoi(second.symbol().c_str()) << "/n";
                else
                {
                    if (!sTable.contains(second.symbol()))
                        sTable.addEntry(second.symbol(), lineCount++ + 1);
                    outfile << "0" << code.toBinary(sTable.getAddress(second.symbol())) << "/n";
                }
            }
            else if (second.instructionType() == C_INSTRUC)
                outfile << "111" << code.comp(second.comp()) << code.comp(second.dest()) << code.jump(second.jump()) << "/n";
        }
    }
    else
        cout << "Argument Error" << endl;
}