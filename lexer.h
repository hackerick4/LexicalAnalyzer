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
	int findLITERAL (string s);
	bool isSymbol(string s);
	int getToken_AlphaStart(string s);
	bool isNum(const int c ){return c >= '0' && c <= '9';}
    bool isAlpha(const int c ){return ( ( c >= 'a' && c <= 'z' ) ||( c >= 'A' && c <= 'Z' )||  c == '_');}
    bool isAlphaNum( const int c ) {return ( isNum( c ) || isAlpha( c ) || c == '_' );}
public:
	void setCurrentLine(int);
	void analyze(string s);
};

#endif