#ifndef LEXER 
#define LEXER
#pragma once
#include <string>
#include <iostream>

class lexer
{
private:
	int currentLine;
	std::string source;
	int getToken_NumStart(std::string s);
	int getToken_OtherStart(std::string s);
	int findLITERAL (std::string s);
	bool isSymbol(std::string s);
	int getToken_AlphaStart(std::string s);
	bool isNum(const int c ){return c >= '0' && c <= '9';}
    bool isAlpha(const int c ){return ( ( c >= 'a' && c <= 'z' ) ||( c >= 'A' && c <= 'Z' )||  c == '_');}
    bool isAlphaNum( const int c ) {return ( isNum( c ) || isAlpha( c ) || c == '_' );}
public:
	void setCurrentLine(int line){ currentLine=line; };
	void analyze(std::string s);
};

#endif