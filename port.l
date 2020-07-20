%{
#include <stdlib.h>
#include "y.tab.h"

extern void yyerror(char *msg);
%}

%option noyywrap

%%
"program" {return start_program;}
"endprogram" {return end_program;}
"while" {return whilestmt;}
"print" {return print;}
":=" 	{return DECL;}
">=" 	{return GE;}
"<=" 	{return LE;}
"==" 	{return E;}
"!=" 	{return NE;}
"||" 	{return OR_;}
"&&" 	{return AND_;}
[0-9]+	{yylval.iValue = atoi(yytext); return num;}
[a-zA-Z] {yylval.id = yytext[0]; return var;}
[-!&|><+*/();={}:] {return yytext[0];}
[ \t\n]	{;}
.	{yyerror("caractere nao identificado");}

%%
