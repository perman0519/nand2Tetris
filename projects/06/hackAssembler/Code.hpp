#ifndef CODE_HPP
# define CODE_HPP
# include <iostream>
using namespace std;

class Code
{
public:
    Code();
    ~Code();

    string comp(string comp);
    string dest(string dest);
    string jump(string jump);
    string toBinary(int address);
};

#endif