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

#endif