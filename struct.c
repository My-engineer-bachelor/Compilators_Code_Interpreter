#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "linkedList.c"

int getValueFromTable(char c, SymbolsTable symbolsTable); 
void updateTable(char c, int value, SymbolsTable symbolsTable); 	
int varExists(char c, SymbolsTable symbolsTable);
void createVarInTable(char c, int value, SymbolsTable symbolsTable);
//enums
enum typeNode{typeId, typeConst, typeOp};
enum typeOperation{STMT, ASSIGN, PRINT, IF, WHILE, FOR, MULT, DIV, SUM, SUB, GREATER, LESS, GREATER_EQUALS, LESS_EQUALS, EQUALS, DIFFERENT, AND, OR, NOT, DECLARATION};
//structs
struct nodeId{
	char id;
};
struct nodeConst{
	int value;
};
struct nodeStmt{
	int typeOperation;
	int numArgs;
	struct treeNode *op[];
};
struct treeNode{
	int typeNode;
	union {
		struct nodeId nodeId;
		struct nodeConst nodeConst;
		struct nodeStmt nodeStmt;
	};
};
LinkedList *linkedList;
struct treeNode *buildNodeId(char var){
	struct treeNode *node;
	node = (struct treeNode*) malloc(sizeof(struct treeNode));
	node->typeNode = typeId;
	node->nodeId.id = var;
	return node;
}
struct treeNode *buildNodeConst(int value){
	struct treeNode *node;
	node = (struct treeNode*)malloc(sizeof(struct treeNode));
	node->typeNode = typeConst;
	node->nodeConst.value = value;
	return node;
}
struct treeNode *buildNodeStmt(int op, int numArgs, ...){
	va_list ap;
	struct treeNode *node = (struct treeNode*)malloc(sizeof(struct treeNode) + (numArgs)*sizeof(struct treeNode*));
	node->typeNode = typeOp;
	node->nodeStmt.typeOperation = op;
	node->nodeStmt.numArgs = numArgs;
	va_start(ap, numArgs);
	for(int i = 0; i < numArgs; i++){
		node->nodeStmt.op[i] = va_arg(ap, struct treeNode*);
	} 
	va_end(ap);
	return node;
}
int execute(struct treeNode *node){
	addSymbolsTable(linkedList);
	int value = 0;
	switch(node->typeNode){
		case typeConst:{
			value = node->nodeConst.value;
			break;
		}
	    	case typeId:{
			int i;
			for(i = linkedList->size; i >= 0; i--){
				SymbolsTable *symbolsTable;
				symbolsTable = getSymbolsTable(linkedList, i);
				if (varExists(node->nodeId.id, *symbolsTable)){
					value = getValueFromTable(node->nodeId.id, *symbolsTable);		
					break;
				}	
			}			
			break;
		}
		case typeOp:{
			switch (node->nodeStmt.typeOperation) {		
				case STMT:{
					execute(node->nodeStmt.op[0]); 
					execute(node->nodeStmt.op[1]);
					break;
				}	  
				case ASSIGN:{
					updateTable(node->nodeStmt.op[0]->nodeId.id, execute(node->nodeStmt.op[1]), linkedList->last->symbolsTable); 
					break;
				}
				case DECLARATION:{
					char id = node->nodeStmt.op[0]->nodeId.id;
					//check if variable exists
					if (varExists(id, linkedList->last->symbolsTable)){					
						printf("Erro: variavel %c ja foi declarada nesse escopo\n", id);
						exit(1);							
					}
					//create variable
					createVarInTable(id, execute(node->nodeStmt.op[1]), linkedList->last->symbolsTable);
					break;
				}
				case WHILE:{
					while(execute(node->nodeStmt.op[0])){
						execute(node->nodeStmt.op[1]);
					}
				}
				case PRINT:{
					printf("Printing %d\n", execute(node->nodeStmt.op[0])); 
					break;
				}
				case MULT:{
					value = execute(node->nodeStmt.op[0]) * execute(node->nodeStmt.op[1]);
					break;
				}
				case DIV:{
					value = execute(node->nodeStmt.op[0]) / execute(node->nodeStmt.op[1]);
					break;
				}
				case SUM:{
					value = execute(node->nodeStmt.op[0]) + execute(node->nodeStmt.op[1]);
					break;
				}
				case SUB:{
					value = execute(node->nodeStmt.op[0]) - execute(node->nodeStmt.op[1]);
					break;
				}
				case GREATER:{
					value = execute(node->nodeStmt.op[0]) > execute(node->nodeStmt.op[1]);
					break;
				}
				case LESS:{
					value = execute(node->nodeStmt.op[0]) < execute(node->nodeStmt.op[1]);
					break;
				}
				case GREATER_EQUALS:{
					value = execute(node->nodeStmt.op[0]) >= execute(node->nodeStmt.op[1]);
					break;
				}
				case LESS_EQUALS:{
					value = execute(node->nodeStmt.op[0]) <= execute(node->nodeStmt.op[1]);
					break;
				}
				case EQUALS:{
					value = execute(node->nodeStmt.op[0]) == execute(node->nodeStmt.op[1]);
					break;
				}
				case DIFFERENT:{
					value = execute(node->nodeStmt.op[0]) != execute(node->nodeStmt.op[1]);
					break;
				}
				case AND:{
					value = execute(node->nodeStmt.op[0]) && execute(node->nodeStmt.op[1]);
					break;
				}
				case OR:{
					value = execute(node->nodeStmt.op[0]) || execute(node->nodeStmt.op[1]);
					break;
				}
				case NOT:{
					value = !execute(node->nodeStmt.op[0]);
					break;
				}
			}
 		}
	}	
	//remove variable from the scope
	removeLastSymbolsTable(linkedList);
	return value;
}
//maps a-zA-Z in 0-51 table 
int getIdentifierFromTable(char c){
	int index = -1;
	if(islower(c)){	
		index = c - 'a' + 26;
	}else if(isupper(c)){
		index = c - 'A';
	}
	return index;	
}
int getValueFromTable(char c, SymbolsTable symbolsTable){
	int id = getIdentifierFromTable(c);
	if (symbolsTable.declaredVars[id] == 1){
		return symbolsTable.table[getIdentifierFromTable(c)];
	}else{
		printf("Error: variable %c not declared\n", c);
		exit(1);
	}
}
void updateTable(char c, int value, SymbolsTable symbolsTable){
	int id = getIdentifierFromTable(c);
	symbolsTable.declaredVars[id] = 1;
	symbolsTable.table[id] = value;
}
void createVarInTable(char c, int value, SymbolsTable symbolsTable){
	int id = getIdentifierFromTable(c);
	if (varExists(c, symbolsTable)){
		symbolsTable.declaredVars[id] = 1;
		symbolsTable.table[id] = value;
	}else{
		printf("Erro: variable %c already was declared in this scope\n", c);
		exit(1);
	}
}
int varExists(char c, SymbolsTable symbolsTable){
	return symbolsTable.declaredVars[getValueFromTable(c, symbolsTable)];
}

