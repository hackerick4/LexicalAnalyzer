#include<iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "lexer.h"

#define MAX_ID_LEN 255
#define MIN_TOK_VAL 300
using namespace std;

void readResouce (string &s){
	ifstream fin;
	fin.open("source.c");
	string readIn;
    while (getline(fin,readIn)){
		s.append(readIn);
	}
}

int main (){
	 ifstream fin;
	 lexer lex ;
	 fin.open("source.c");
	 string readIn;
	 int line=1;
     while (getline(fin,readIn)){
		 lex.setCurrentLine(line);
		lex.analyze(readIn);
		++line;
	 }
	 getch();
     return 0;
}