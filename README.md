# Compilators_
This repository contains the source code of activity of the course "Compilators" where a code interpreter was implemented using LEX and YACC (with the construction of a syntax tree).
This interpretor contains checkings for:
* Integer type
* Arithmetic expressions +,-,\*,/
* Relational expressions >,<,<=,>=,==,!=
* Logical expressions &&, ||, !
* Loop WHILE
* Block definitions and statements sequences
* Symbols table using for the variables scope creation (global and local variables)

To compile this project type the following commands:

1. yacc -d port.y
2. lex port.l
3. gcc lex.yy.c y.tab.c
4. ./a < input.txt

This project has some bugs which I aim to solve ASAP. Any doubts feel yourself free to reach me out: m228117@dac.unicamp.br. 
   
