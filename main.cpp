#include<iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "lexer.h"

using namespace std;


int main (){
	 ifstream fin;
	 lexer lex ;
	 fin.open("source.c");
	 string readIn;
	 unsigned int line=1;
     while (getline(fin,readIn)){
		 lex.setCurrentLine(line);
		lex.analyze(readIn);
		++line;
	 }
	 getch();
     return 0;
}