%{
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
#include "ttree.h"
#include "ttfunc.cpp"
#include "symboltree.h"
#include "mipscode.cpp"
#include "threecode.cpp"


ttnode *root;
extern "C" int yylex();
extern "C" int yyparse();
extern int yylineno;
void yyerror(string s);

%}

%union 
{
	ttnode *tval;
}


%token <tval> GET PUT MAIN
%token <tval> LE_OP GE_OP EQ_OP NE_OP LT_OP GT_OP AD_OP SU_OP MU_OP DI_OP
%token <tval> AND OR
%token <tval> CONST
%token <tval> IF ELSE WHILE FOR IN CONTINUE BREAK RETURN 

%token <tval> INT_CONSTANT FLOAT_CONSTANT TRUE FALSE IDENTIFIER INT FLOAT BOOL

%type <tval> program declaration_list declaration variable_declaration variable_list variable
%type <tval> type epsilon function_declaration parameters parameter_list parameter
%type <tval> main_function code_block statement condition_stat loop_stat
%type <tval> for_loop while_loop return_stat read write
%type <tval> expression logic_expression and_expression relation_expression simple_expression mul_expression unary_expression
%type <tval> climax call arguments argument_list constants
%type <tval> op1 op2 op3 unary_op

%%

program 
	: declaration_list main_function
		{ root = make_node("","program",$1,$2,NULL); }
	;
	
declaration_list 
	: declaration_list declaration 
		{ $$ = make_node("","declaration_list",$1,$2,NULL); }
	| epsilon
		{ $$ = make_node("","declaration_list",$1,NULL,NULL); }
	;

declaration 
	: variable_declaration 
		{ $$ = make_node("","declaration",$1,NULL,NULL); }
	| function_declaration
		{ $$ = make_node("","declaration",$1,NULL,NULL); }
	;

variable_declaration 
	: type variable_list ';'
		{ $$ = make_node("","variable_declaration",$1,$2,NULL); }
	;

variable_list 
	: variable_list ',' variable 
		{ $$ = make_node("","variable_list",$1,$3,NULL); }
	| variable
		{ $$ = make_node("","variable_list",$1,NULL,NULL); }
	;

variable 
	: IDENTIFIER
		{ $$ = make_node($1->item,"variable",$1,NULL,NULL); }
	;

type 
	: INT 
		{ $$ = make_node("","type",$1,NULL,NULL); }
	| FLOAT
		{ $$ = make_node("","type",$1,NULL,NULL); }
	| BOOL
		{ $$ = make_node("","type",$1,NULL,NULL); }
	;

epsilon 
	: 
		{ $$ = make_node("","epsilon",NULL,NULL,NULL); }
	;

function_declaration 
	: type IDENTIFIER '(' parameters ')' '{' code_block '}' 
		{ $$ = make_node($2->item,"function_declaration",$1,$4,$7); }
	| IDENTIFIER '(' parameters ')' '{' code_block '}'
		{ $$ = make_node($1->item,"function_declaration",$3,$6,NULL); }
	;
	
parameters 
	: parameter_list 
		{ $$ = make_node("","parameters",$1,NULL,NULL); }
	| epsilon
		{ $$ = make_node("","parameters",$1,NULL,NULL); }
	;
	
parameter_list 
	: parameter_list ',' parameter 
		{ $$ = make_node("","parameter_list",$1,$3,NULL); }
	| parameter
		{ $$ = make_node("","parameter_list",$1,NULL,NULL); }
	;

parameter 
	: type variable
		{ $$ = make_node("","parameter",$1,$2,NULL); }
	;
	
main_function 
	: MAIN '{' code_block '}'
		{ $$ = make_node("","main_function",$3,NULL,NULL); }
	;
	
code_block 
	: code_block statement 
		{ $$ = make_node("","code_block",$1,$2,NULL); }
	| statement
		{ $$ = make_node("","code_block",$1,NULL,NULL); }
	;
	
statement 
	: variable_declaration 
		{ $$ = make_node("","statement",$1,NULL,NULL); }
	| expression ';' 
		{ $$ = make_node("","statement",$1,NULL,NULL); }
	| condition_stat 
		{ $$ = make_node("","statement",$1,NULL,NULL); }
	| loop_stat 
		{ $$ = make_node("","statement",$1,NULL,NULL); }
	| BREAK ';' 
		{ $$ = make_node("break","statement",$1,NULL,NULL); }
	| CONTINUE ';' 
		{ $$ = make_node("continue","statement",$1,NULL,NULL); }
	| return_stat ';' 
		{ $$ = make_node("","statement",$1,NULL,NULL); }
	| read ';'
		{ $$ = make_node("","statement",$1,NULL,NULL); }
	| write ';'
		{ $$ = make_node("","statement",$1,NULL,NULL); }
	| error ';' { yyerrok;                  }
	;

condition_stat 
	: IF '(' expression ')' '{' code_block '}' ELSE '{' code_block '}' 
		{ $$ = make_node("op","condition_stat",$3,$6,$10); }
	| IF '(' expression ')' '{' code_block '}'
		{ $$ = make_node("","condition_stat",$3,$6,NULL); }
	;

loop_stat 
	: for_loop 
		{ $$ = make_node("","loop_stat",$1,NULL,NULL); }
	| while_loop
		{ $$ = make_node("","loop_stat",$1,NULL,NULL); }
	;

for_loop 
	: FOR '(' variable IN simple_expression ')' '{' code_block '}'
		{ $$ = make_node("","for_loop",$3,$5,$8); }
	;

while_loop 
	: WHILE '(' expression ')' '{' code_block '}'
		{ $$ = make_node("","while_loop",$3,$6,NULL); }
	;

return_stat 
	: RETURN  
		{ $$ = make_node("","return_stat",$1,NULL,NULL); }
	| RETURN expression
		{ $$ = make_node("op","return_stat",$1,$2,NULL); }
	;

read 
	: GET '(' variable ')' 
		{ $$ = make_node("get","read",$3,NULL,NULL); }
	;

write 
	: PUT '(' expression ')'
		{ $$ = make_node("put","write",$3,NULL,NULL); }
	;

expression 
	: variable '=' expression 
		{ $$ = make_node("=","expression",$1,$3,NULL); }
	| logic_expression
		{ $$ = make_node("","expression",$1,NULL,NULL); }
	;
	
logic_expression 
	: logic_expression OR and_expression 
		{ $$ = make_node("or","logic_expression",$1,$3,NULL); }
	| and_expression
		{ $$ = make_node("","logic_expression",$1,NULL,NULL); }
	;

and_expression 
	: and_expression AND relation_expression 
		{ $$ = make_node("and","and_expression",$1,$3,NULL); }
	| relation_expression
		{ $$ = make_node("","and_expression",$1,NULL,NULL); }
	;
	
relation_expression 
	: relation_expression op3 simple_expression 
		{ $$ = make_node("op","relation_expression",$1,$2,$3); }
	| simple_expression
		{ $$ = make_node("","relation_expression",$1,NULL,NULL); }
	;
	
simple_expression 
	: simple_expression op1 mul_expression 
		{ $$ = make_node("op","simple_expression",$1,$2,$3); }
	| mul_expression
		{ $$ = make_node("","simple_expression",$1,NULL,NULL); }
	;

mul_expression 
	: mul_expression op2 unary_expression 
		{ $$ = make_node("op","mul_expression",$1,$2,$3); }
	| unary_expression
		{ $$ = make_node("","mul_expression",$1,NULL,NULL); }
	;

unary_expression 
	: unary_op unary_expression 
		{ $$ = make_node("op","unary_expression",$1,$2,NULL); }
	| climax
		{ $$ = make_node("","unary_expression",$1,NULL,NULL); }
	;

climax 
	: '(' expression ')' 
		{ $$ = make_node("op","climax",$2,NULL,NULL); }
	| call 
		{ $$ = make_node("","climax",$1,NULL,NULL); }
	| constants 
		{ $$ = make_node("","climax",$1,NULL,NULL); }
	| variable
		{ $$ = make_node("","climax",$1,NULL,NULL); }
	;

call 
	: IDENTIFIER '(' arguments ')'
		{ $$ = make_node($1->item,"call",$3,NULL,NULL); }
	;

arguments 
	: argument_list 
		{ $$ = make_node("","arguments",$1,NULL,NULL); }
	| epsilon
		{ $$ = make_node("","arguments",$1,NULL,NULL); }
	;

argument_list 
	: argument_list ',' expression 
		{ $$ = make_node("","argument_list",$1,$3,NULL); }
	| expression
		{ $$ = make_node("","argument_list",$1,NULL,NULL); }
	;

constants 
	: INT_CONSTANT
		{ $$ = make_node("","constants",$1,NULL,NULL); }
	| FLOAT_CONSTANT
		{ $$ = make_node("","constants",$1,NULL,NULL); }
	| TRUE 
		{ $$ = make_node("","constants",$1,NULL,NULL); }
	| FALSE
		{ $$ = make_node("","constants",$1,NULL,NULL); }
	;

op1 
	: AD_OP 
		{ $$ = make_node("","op1",$1,NULL,NULL); }
	| SU_OP
		{ $$ = make_node("","op1",$1,NULL,NULL); }
	;

op2 
	: MU_OP 
		{ $$ = make_node("","op2",$1,NULL,NULL); }
	| DI_OP
		{ $$ = make_node("","op2",$1,NULL,NULL); }
	;

op3 
	: GE_OP 
		{ $$ = make_node("","op3",$1,NULL,NULL); }
	| LE_OP 
		{ $$ = make_node("","op3",$1,NULL,NULL); }
	| GT_OP 
		{ $$ = make_node("","op3",$1,NULL,NULL); }
	| LT_OP 
		{ $$ = make_node("","op3",$1,NULL,NULL); }
	| EQ_OP 
		{ $$ = make_node("","op3",$1,NULL,NULL); }
	| NE_OP
		{ $$ = make_node("","op3",$1,NULL,NULL); }
	;

unary_op 
	: SU_OP
		{ $$ = make_node("","unary_op",$1,NULL,NULL); }
	;

%%
bool fail;
void yyerror(string s) 
{
	cerr << "Line " << yylineno << ": " << s << endl;
	fail = 1;
}

int main()
{
	bool failure = yyparse();
	failure |= fail;
	if(failure) 
		std::cerr << "Parsing Failed\n";
	else
	{
		cerr << "Success!\n";
		printtree(root); printtreeold(root, "+-- ");
		mcode << ".text" << endl;
		generatecode(root);
		data();
	}
}