#include <fstream>
#include <conio.h>
#include "lexer.h"

int main (){
	 std::ifstream fin;
	 lexer lex ;
	 fin.open("source.c");
	 std:: string readIn;
	 unsigned int line=1;
     while (std::getline(fin,readIn)){
		 lex.setCurrentLine(line);
		 lex.analyze(readIn);
		 ++line;
	 }
	 getch();
     return 0;
}