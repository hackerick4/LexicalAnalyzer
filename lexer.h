#ifndef LEXER
#define LEXER
#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class lexer
{
private:
	int currentLine;
	string source;
	int getToken_NumStart(string s);
	int getToken_OtherStart(string s);
public:
	void setCurrentLine(int);
	void analyze(string s);
};


#endif