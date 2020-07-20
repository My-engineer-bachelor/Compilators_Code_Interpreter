%{
#include <stdio.h>
#include <stdlib.h>
#include "struct.c"
void yyerror(char *msg);
extern int yylex();
%}
%union{
	int iValue;
	char id;
	struct treeNode *node;
};

%left  ":="
%left '!' "&&" "||"
%left ">=" "<=" "==" "!=" '<' '>'
%left '+' '-' 
%left  '*' '/'
%token <iValue> num
%token <id> var
%token print
%token whilestmt
%token start_program
%token end_program
%token GE
%token LE
%token E
%token NE
%token DECL
%token OR_
%token AND_
%type <node> exp term factor stmt stmts assign declaration

%%
program : start_program stmts end_program	{execute($2); exit(1);}
	    ;

stmts : stmts stmt	{$$ = buildNodeStmt(STMT, 2, $1, $2);}
	  | stmt 	{$$ = $1;}
	  ;

stmt : print exp ';'				{$$ = buildNodeStmt(PRINT, 1, $2);}
	 | declaration				{$$ = $1;}
	 | assign 				{$$ = $1;}
	 | whilestmt '(' exp ')' '{' stmts'}'	{$$ = buildNodeStmt(WHILE, 2, $3,$6);}
	 ;

declaration : var DECL exp ';' 	{
					$$ = buildNodeStmt(DECLARATION, 2, buildNodeId($1), $3);
				}
		;

assign : var '=' exp ';' 	{$$ = buildNodeStmt(ASSIGN, 2, buildNodeId($1), $3);}
	   ;
exp : 	'!' exp			{$$ = buildNodeStmt(NOT, 1, $2);}
	| exp AND_ exp  	{$$ = buildNodeStmt(AND_, 2, $1, $3);}
	| exp OR_ exp  	{$$ = buildNodeStmt(OR_, 2, $1, $3);}
	| exp GE exp  	{$$ = buildNodeStmt(GREATER_EQUALS, 2, $1, $3);}
	| exp LE exp  	{$$ = buildNodeStmt(LESS_EQUALS, 2, $1, $3);}
	| exp E exp  	{$$ = buildNodeStmt(EQUALS, 2, $1, $3);}
	| exp NE exp  	{$$ = buildNodeStmt(DIFFERENT, 2, $1, $3);}
	| exp '>' exp  		{$$ = buildNodeStmt(GREATER, 2, $1, $3);}
	| exp '<' exp  		{$$ = buildNodeStmt(LESS, 2, $1, $3);}
	| exp '+' term	{$$ = buildNodeStmt(SUM, 2, $1, $3);}
	| exp '-' term  	{$$ = buildNodeStmt(SUB, 2, $1, $3);}
	| term 				{$$ = $1;}
	;

term : term '*' factor 		{$$ = buildNodeStmt(MULT, 2, $1, $3);}	 
	 | term '/' factor  	{$$ = buildNodeStmt(DIV, 2, $1, $3);}
	 | factor 		{$$ = $1;}
	 ; 

factor : '(' exp ')' 		{$$ = $2;}
	   | num		{$$ = buildNodeConst($1);}
	   | '-' num		{$$ = buildNodeConst(-$2);}
	   | var		{$$ = buildNodeId($1);}
	   ;

%%

void yyerror(char *msg){
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

int main(){
	linkedList = createLinkedList();	
	return yyparse();
}
