#ifndef SYMBOL
#define SYMBOL
struct Symbol {
  char * str;
  char * type;
};

Symbol res[] = {
	{"if", "IF"} , 
	{"while", "WHILE"},
	{"(","LEFTP" }, 
	{")","RIGHTP" },
	{"{" ,"BLOCKL" },
	{"}","BLOCKR"}, 
	{";","SEMI"}, 
	{",","COMMA"},
	{"+","ADD"}, 
	{"-","SUB"}, 
	{"*","MUL"}, 
	{"/","DIV"},
	{"<","COMP"}, 
	{"<=","COMP"}, 
	{">","COMP"}, 
	{">=","COMP"}, 
	{"!=","COMP"}, 
	{"==","COMP"}, 
	{"=","ASSIGN"}, 
	
};

bool isNum(const int c ){
   return c >= '0' && c <= '9';
}
bool isAlpha(const int c ){
   return ( ( c >= 'a' && c <= 'z' ) ||
    ( c >= 'A' && c <= 'Z' )||  c == '_');
}

 bool isAlphaNum( const int c ) {
  return ( isNum( c ) || isAlpha( c ) || c == '_' );
}


#endif