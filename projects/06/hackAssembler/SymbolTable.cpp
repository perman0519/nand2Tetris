#include "SymbolTable.hpp"

SymbolTable::SymbolTable(void)
{
    // 사전 정의된 기호
    table.insert({"R0", 0});
    table.insert({"R1", 1});
    table.insert({"R2", 2});
    table.insert({"R3", 3});
    table.insert({"R4", 4});
    table.insert({"R5", 5});
    table.insert({"R6", 6});
    table.insert({"R7", 7});
    table.insert({"R8", 8});
    table.insert({"R9", 9});
    table.insert({"R10", 10});
    table.insert({"R11", 11});
    table.insert({"R12", 12});
    table.insert({"R13", 13});
    table.insert({"R14", 14});
    table.insert({"R15", 15});
    table.insert({"SCREEN", 16384});
    table.insert({"KBD", 24576});
    table.insert({"SP", 0});
    table.insert({"LCL", 1});
    table.insert({"ARG", 2});
    table.insert({"THIS", 3});
    table.insert({"THAT", 4});
}

SymbolTable::~SymbolTable(void) { }

bool SymbolTable::contains(string symbol)
{
    if (table[symbol])
        return (true);
    else
        return (false);
}

void SymbolTable::addEntry(string symbol, int address)
{
    table.insert({symbol, address});
}

int SymbolTable::getAddress(string symbol)
{
    return (table[symbol]);
}
