#ifndef LEXER
#define LEXER
#pragma once
//#include "symbol.h"
#include <string>;
#include <iostream>
#include <vector>
using namespace std;
class lexer
{
private:
	int currentLine;
	void printInvalid_lexeme(string);
	void findIDAndNum(string &s);
	void checkSymbol(string &s);
	vector<int> validBit;
public:
	void setCurrentLine(int);
	void analyze(string s);
};


#endif