#include "lexer.h"
#include "symbol.h"
#include <locale>
#include <iostream>
#include <algorithm>
void lexer::setCurrentLine(int line){
	currentLine=line;
}
bool isNum(const int c ){
	 return c >= '0' && c <= '9';
}
bool isAlpha(const int c ){
	 return ( ( c >= 'a' && c <= 'z' ) ||
    ( c >= 'A' && c <= 'Z' )|| c == '_' );
}

 bool isAlphaNum( const int c ) {
  return ( isNum( c ) || isAlpha( c ) || c == '_' );
}

void lexer::checkSymbol(string &s){
	int found = -1;
	for (size_t i = 0 ; i < sizeof (res) / sizeof (Symbol);++i){
	    found = s.find( res[i].str);
		if(found>=0) {
			cout << res[i].type << ":" <<  res[i].str<<endl;
		    s.erase(found,strlen(res[i].str));
		}
		else if (found!=std::string::npos) --i;
	}
}

bool isSymbol(string &s){
	int found;
	for (size_t i = 0 ; i < sizeof (res) / sizeof (Symbol);++i){
		if (strcmp (s.c_str(),res[i].str)==0) return true;
		//found = s.find( res[i].str);
	}
	return false;
}

void findLITERAL(string &s){
	int pairs = -1 , from=-1 , to=-1;
	string liter;
	for (size_t i = 0 ; i <s.length() ; ++i){
		 if (s.at(i)=='"' ){ //"findLITERAL"!!
			 if (pairs==-1){cout <<"LITERAL : "; from = i;} 
			pairs*=-1;
			to = i;
		}
	}
	if (from==-1) return;
	liter = s.substr(from,to-from+1);
	s.erase(from,to-from+1);
	cout << liter<<endl;
}


void lexer::printInvalid_lexeme(string s){
	char *blank= " ";
	for ( string::iterator it = s.begin(); it!=s.end();++it){
		if (*it != *blank){ 
			cout <<"* Error: invalid lexeme " << *it << " found at line"<< currentLine << endl;
			break;
			}
	}

}
void lexer::analyze(string source){
	findLITERAL(source);
	const char * c_s =source.c_str();
	string outPut;
	for ( size_t i = 0 ; i <= strlen(c_s);++i){
		if (isAlpha(c_s[i])){
			while(isAlphaNum(c_s[i])){ 
					outPut+=c_s[i];
					++i;
					validBit.push_back(i);
				}
			if (!isSymbol(outPut)){
				cout << "ID : " <<outPut<<endl;
				outPut.clear();
			}
			else outPut.clear();
			continue;
			}
		else if (isNum(c_s[i])){
			while(isNum(c_s[i])){ 
					outPut+=c_s[i];
					++i;
					validBit.push_back(i);
				}
			cout << "NUM : " <<outPut<<endl;
			outPut.clear();
		}
		else checkSymbol(source);
	}
//	cout << source << endl;
}
	
