#include "lexer.h"
#include "symbol.h"
#include <locale>
#include <iostream>
#include <algorithm>

void lexer::setCurrentLine(int line){
  currentLine=line;
}

void findSymbol(string &s){
  int found = -1;
  for (size_t i = 0 ; i < sizeof (res) / sizeof (Symbol);++i){
      found = s.find( res[i].str);
    if(found>=0) {
      cout << res[i].type << ":" <<  res[i].str<<endl;
        s.erase(found,strlen(res[i].str));
    }
     if (found!=std::string::npos) --i;
  }
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

void lexer::findID(string &s){
	const char * c_s =s.c_str();
	string outPut;
	for ( size_t i = 0 ; i <= strlen(c_s);++i){
		if (isAlpha(c_s[i])){
			while(isAlphaNum(c_s[i])){ 
					outPut+=c_s[i];
					++i;
					validBit.push_back(i);
				}
			    cout << "ID : " <<outPut<<endl;
				outPut.clear();
			
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

	}
 
}
void lexer::printInvalid_lexeme(string s){
  char *blank= " ";
  for ( string::iterator it = s.begin(); it!=s.end();++it){
    if (*it != *blank && !isAlphaNum(*it)){ 
      cout <<"* Error: invalid lexeme " << *it << " found at line"<< currentLine << endl;
      break;
      }
  }
}
void lexer::analyze(string source){
  char * c_source = new char [source.length()+1];
    strncpy (c_source, source.c_str(),source.length()+1);
  findLITERAL(source);
  findSymbol(source);
  findID(source);
  source.erase(remove_if(source.begin(), source.end(), isspace), source.end());
 printInvalid_lexeme(source);
}  