#include "lexer.h"
#include "symbol.h"
#include <iostream>
#include <string.h>

void lexer::setCurrentLine(int line){
  currentLine=line;
}
int lexer::findLITERAL(string s){
	 int pairs = -1;
	 string liter;
	 string::iterator it = s.begin();
	 do{
		 liter+=*it;
		 if (*it=='"') pairs*=-1;
			++it;
	 }while (pairs==1);
	 cout<<"LITERAL," << liter<<endl;
	 return distance(s.begin(),it);
}
bool lexer::isSymbol(string s){
for (size_t i = 0 ; i < sizeof (res) / sizeof (Symbol);++i){
	int found = s.find( res[i].str);
	  if(found>=0 )   {
		  cout << res[i].type << ", " <<  res[i].str<<endl;
		  isSymbol(s.substr(found+res[i].str.length(),string::npos));
		  return true;
	  }
}
	return false;
}

int lexer::getToken_AlphaStart(string s){
	string check;
	string::iterator it;
	for ( it = s.begin() ; it!=s.end()&&isAlphaNum(*it) ; ++it)
		check+=*it;
	if (! isSymbol(check)) cout<<"ID, "<<check<<endl ;
	return distance(s.begin(),it);
}

int lexer::getToken_NumStart(string s){
	string check;
	string::iterator it;
	bool valid = true;
	for ( it = s.begin() ; it!=s.end()&& isAlphaNum(*it) ; ++it)
		check+=*it;
	for (string::iterator it = check.begin() ; it!=check.end() ; ++it)
		if (isAlpha(*it)) {valid=false; break;}
	if (valid)cout <<"NUM, " << check  << endl;
	else cout <<"* Error: invalid lexeme " << check << " found at line"<< currentLine << endl;
	return distance(s.begin(),it);
}

int lexer::getToken_OtherStart(string s){
	string check;
	string::iterator it;
	if (s[0] == '"') return findLITERAL(s);
	for ( it = s.begin() ; it!=s.end()&&!isAlphaNum(*it)&&!isspace(*it)&&*it!='"' ; ++it){
		check+=*it;
		}
    if (! isSymbol(check)) cout <<"* Error: invalid lexeme " << check << " found at line"<< currentLine << endl;
	return distance(s.begin(),it);
}

void lexer::analyze(string input){
	source.assign(input);
	for (string::iterator source_it = source.begin(); source_it!=source.end();){
		if (isspace(*source_it)) ++source_it;
		else if (isAlpha(*source_it)) 
			source_it+= getToken_AlphaStart(source.substr( distance(source.begin(),source_it) , string::npos ));
		else if (isNum(*source_it)) 
			source_it+= getToken_NumStart(source.substr( distance(source.begin(),source_it) , string::npos ));
		else //NOT alphabet OR Number
			source_it+= getToken_OtherStart(source.substr( distance(source.begin(),source_it) , string::npos ));
	}
}  