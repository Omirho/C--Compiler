%{
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
#include "ttree.h"
#include "awry.tab.h"
#define YY_DECL extern "C" int yylex()
#define YYPRINT(file, type, value)   yyprint (file, type, value)
#define token(s) { (yylval.tval) = new ttnode(); (yylval.tval)->item = yytext; (yylval.tval)->identifier = #s; return s; }
#define tokk(val,s) { (yylval.tval) = new ttnode(); (yylval.tval)->item = val; (yylval.tval)->identifier = #s; return s; }

%}
%option yylineno

SPACE ([ \t])
BLANKSPACES ([ \t]+)
POS_DIG ([1-9])
DIG ([0-9])
DECIMAL ([0-9]+\.[0-9]+)
NUMBER ({DIG}+)
LOWER ([a-z])
LETTER ({LOWER}|[A-Z]|_)
IDENTIFIER ([A-Za-z_]([A-Za-z0-9_])*)
STRING_LITERAL (\"(\\.|[^\\"])*\")

%%

"if"			{ token( IF);}
"else" 			{ token( ELSE); }
"while" 		{ token( WHILE); }
"foreach" 		{ token( FOR); }
"int" 			{ token( INT); }
"float" 		{ token( FLOAT); }
"bool"			{ token( BOOL); }
"true" 			{ tokk("1", TRUE); }
"false" 		{ tokk("0", FALSE);}
"in" 			{ token( IN); }
"get" 			{ token( GET); }
"put" 			{ token( PUT); }
"puts" 			{ token( PUTS); }
"break" 		{ token( BREAK); }
"continue" 		{ token( CONTINUE); }
"return" 		{ token( RETURN); }
"main" 			{ token( MAIN); }
"and" 			{ token( AND); }
"or" 			{ token( OR); }
"const"			{ token( CONST); }

"==" 			{ token( EQ_OP); }
"!=" 			{ token( NE_OP); }
"<=" 			{ token( LE_OP); }
">=" 			{ token( GE_OP); }
"(" 			{ return '('; }
")" 			{ return ')'; }
"{" 			{ return '{'; }
"}" 			{ return '}'; }
"<" 			{ token( LT_OP); }
">" 			{ token( GT_OP); }
"+" 			{ token( AD_OP); }
"-" 			{ token( SU_OP); }
"*" 			{ token( MU_OP); }
"/" 			{ token( DI_OP); }
";" 			{ return ';'; }
"," 			{ return ','; }
"=" 			{ return '='; }

{IDENTIFIER} 	{ token(IDENTIFIER);}
{DECIMAL} 		{ token(FLOAT_CONSTANT);	}
{NUMBER}        { token(INT_CONSTANT);	}
{STRING_LITERAL} {token(STRING);} 
{BLANKSPACES} 
\n				{}
.  				cerr << "TOKEN ERROR\n" ;

%%

int yywrap(){return 1;}