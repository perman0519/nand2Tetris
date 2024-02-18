#include "Code.hpp"

Code::Code(void) { }

Code::~Code(void) { }

string Code::comp(string comp)
{
    // a = 0 인 경우
    if (comp == "0")
        return ("0101010");
    else if (comp == "1")
        return ("0111111");
    else if (comp == "-1")
        return ("0111010");
    else if (comp == "D")
        return ("0001100");
    else if (comp == "A")
        return ("0110000");
    else if (comp == "!D")
        return ("0001101");
    else if (comp == "!A")
        return ("0110001");
    else if (comp == "~D")
        return ("0001101");
    else if (comp == "~A")
        return ("0110011");
    else if (comp == "D+1")
        return ("0011111");
    else if (comp == "A+1")
        return ("0110111");
    else if (comp == "D-1")
        return ("0001110");
    else if (comp == "A-1")
        return ("0110010");
    else if (comp == "D+A")
        return ("0000010");
    else if (comp == "D-A")
        return ("0010011");
    else if (comp == "A-D")
        return ("0000111");
    else if (comp == "D&A")
        return ("0000000");
    else if (comp == "D|A")
        return ("0010101");

    // a = 1 인 경우
    if (comp == "M")
        return ("1110000");
    else if (comp == "!M")
        return ("1110001");
    else if (comp == "~M")
        return ("1110011");
    else if (comp == "M+1")
        return ("1110111");
    else if (comp == "M-1")
        return ("1110010");
    else if (comp == "D+M")
        return ("1000010");
    else if (comp == "D-M")
        return ("1010011");
    else if (comp == "M-D")
        return ("1000111");
    else if (comp == "D&M")
        return ("1000000");
    else if (comp == "D|M")
        return ("1010101");

    return ("");
}

string Code::dest(string dest)
{
    if (dest == "M")
        return ("001");
    else if (dest == "D")
        return ("010");
    else if (dest == "MD")
        return ("011");
    else if (dest == "A")
        return ("100");
    else if (dest == "AM")
        return ("101");
    else if (dest == "AD")
        return ("110");
    else if (dest == "AMD")
        return ("111");
    else
        return ("000");
}

string Code::jump(string jump)
{
    if (jump == "JGT")
        return ("001");
    else if (jump == "JEQ")
        return ("010");
    else if (jump == "JGE")
        return ("011");
    else if (jump == "JLT")
        return ("100");
    else if (jump == "JNE")
        return ("101");
    else if (jump == "JLE")
        return ("110");
    else if (jump == "JMP")
        return ("111");
    else
        return ("000");
}

string Code::toBinary(int address)
{
    return (bitset<16>(address).to_string());
}
