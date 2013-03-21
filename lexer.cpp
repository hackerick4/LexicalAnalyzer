#include "lexer.h"
#include "symbol.h"

int lexer::findLITERAL(std::string s){
	 int pairs = -1;
	 std::string liter;
	 std::string::iterator it = s.begin();
	 do{
		 liter+=*it;
		 if (*it=='"') pairs*=-1;
			++it;
	 }while (pairs==1);
	 std::cout<<"LITERAL," << liter<<std::endl;
	 return distance(s.begin(),it);
}
bool lexer::isSymbol(std::string s){
for (size_t i = 0 ; i < sizeof (res) / sizeof (Symbol);++i){
	int found = s.find( res[i].str);
	  if(found>=0 )   {
		  std::cout << res[i].type << ", " <<  res[i].str<<std::endl;
		  isSymbol(s.substr(found+res[i].str.length(),std::string::npos));
		  return true;
	  }
}
	return false;
}

int lexer::getToken_AlphaStart(std::string s){
	std::string check;
	std::string::iterator it;
	for ( it = s.begin() ; it!=s.end()&&isAlphaNum(*it) ; ++it)
		check+=*it;
	if (! isSymbol(check)) std::cout<<"ID, "<<check<<std::endl ;
	return distance(s.begin(),it);
}

int lexer::getToken_NumStart(std::string s){
	std::string check;
	std::string::iterator it;
	bool valid = true;
	for ( it = s.begin() ; it!=s.end()&& isAlphaNum(*it) ; ++it)
		check+=*it;
	for (std::string::iterator it = check.begin() ; it!=check.end() ; ++it)
		if (isAlpha(*it)) {valid=false; break;}
	if (valid)std::cout <<"NUM, " << check  << std::endl;
	else std::cout <<"* Error: invalid lexeme " << check << " found at line"<< currentLine << std::endl;
	return distance(s.begin(),it);
}

int lexer::getToken_OtherStart(std::string s){
	std::string check;
	std::string::iterator it;
	if (s[0] == '"') return findLITERAL(s);
	for ( it = s.begin() ; it!=s.end()&&!isAlphaNum(*it)&&!isspace(*it)&&*it!='"' ; ++it){
		check+=*it;
		}
    if (! isSymbol(check)) std::cout <<"* Error: invalid lexeme " << check << " found at line"<< currentLine << std::endl;
	return distance(s.begin(),it);
}

void lexer::analyze(std::string input){
	source.assign(input);
	for (std::string::iterator source_it = source.begin(); source_it!=source.end();){
		if (isspace(*source_it)) ++source_it;
		else if (isAlpha(*source_it)) 
			source_it+= getToken_AlphaStart(source.substr( distance(source.begin(),source_it) , std::string::npos ));
		else if (isNum(*source_it)) 
			source_it+= getToken_NumStart(source.substr( distance(source.begin(),source_it) , std::string::npos ));
		else //NOT alphabet OR Number
			source_it+= getToken_OtherStart(source.substr( distance(source.begin(),source_it) , std::string::npos ));
	}
}  