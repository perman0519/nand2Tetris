#ifndef SYMBOLTABLE_HPP
# define SYMBOLTABLE_HPP
# include <iostream>
# include <unordered_map>
using namespace std;

class SymbolTable{

private:
    unordered_map<string, int> table;

public:
    SymbolTable();
    ~SymbolTable();

    bool contains(string symbol);
    void addEntry(string symbol, int address);
    int getAddress(string symbol);
};

#endif