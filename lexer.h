#ifndef LEXER
#define LEXER
#pragma once
//#include "symbol.h"
#include <string>;
#include <iostream>
using namespace std;
class lexer
{
private:
	int currentLine;
	void printInvalid_lexeme(string);
public:
	void setCurrentLine(int);
	lexer();
	~lexer(void);
	void analyze(string s);
};


#endif