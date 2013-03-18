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
	  if(found>=0 ) {
		  if (found + strlen(res [ i ].str)<s.length() && isAlphaNum(s[ found + strlen(res [i ].str) ]) && isAlphaNum(s [found])) {
			  continue;//cout << "////"<<s[found + strlen(res [i ].str) ]<<endl;
		  }
	      cout << res[i].type << ":" <<  res[i].str<<endl;
          s.replace(found,strlen(res[i].str)," ");
    } if (found!=std::string::npos) --i;}}

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

void lexer::findIDAndNum(string &s){
	const char * c_s =s.c_str();
	string outPut;
	bool valid = true;
	for (  string::iterator it = s.begin(); it!=s.end();++it){
		if (isAlpha(*it)){
			while(isAlphaNum(*it)){ 
					outPut+=*it;
					++it;
				}
			    cout << "ID : " <<outPut<<endl;
				outPut.clear();
			
			}
		else if (isNum(*it)){
			if (isAlpha(*(it+1))) {
				valid = false;
				while(isAlphaNum(*it)){ 
					outPut+=*it;
					++it;
				}
			 cout <<"* Error: invalid lexeme " << outPut << " found at line"<< currentLine << endl;
			}
			while(isNum(*it)){ 
					outPut+=*it;
					++it;
				}
			if (valid)cout << "NUM : " <<outPut<<endl;
			valid = true;
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

  findLITERAL(source);
  findSymbol(source);
  findIDAndNum(source);
  source.erase(remove_if(source.begin(), source.end(), isspace), source.end());
  printInvalid_lexeme(source);
}  