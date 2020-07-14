#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "listaEncadeada.c"
//prototipos
	//busca da table
int getValueFromTable(char c, SymbolsTable symbolsTable); 
	//atualiza table
void updateTable(char c, int value, SymbolsTable symbolsTable); 	
	//verifica se variavel existe
int varExists(char c, SymbolsTable symbolsTable);
	//cria variavel na tabela
void createVarInTable(char c, int value, SymbolsTable symbolsTable);
///enums
enum typeNode{typeId, typeConst, typeOp};
enum typeOperation{STMT, ASSIGN, PRINT, IF, WHILE, FOR, MULT, DIV, SUM, SUB, MAIOR, MENOR, MAIOR_IGUAL, MENOR_IGUAL, IGUAL, DIFERENTE, E, OU, NAO, DECLARATION};
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
//instancias
LinkedList *linkedList;
//funções
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
					//verificar se variavel existe
					if (varExists(id, linkedList->last->symbolsTable)){					
						printf("Erro: variavel %c ja foi declarada nesse escopo\n", id);
						exit(1);							
					}
					//criar variavel
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
				case MAIOR:{
					value = execute(node->nodeStmt.op[0]) > execute(node->nodeStmt.op[1]);
					break;
				}
				case MENOR:{
					value = execute(node->nodeStmt.op[0]) < execute(node->nodeStmt.op[1]);
					break;
				}
				case MAIOR_IGUAL:{
					value = execute(node->nodeStmt.op[0]) >= execute(node->nodeStmt.op[1]);
					break;
				}
				case MENOR_IGUAL:{
					value = execute(node->nodeStmt.op[0]) <= execute(node->nodeStmt.op[1]);
					break;
				}
				case IGUAL:{
					value = execute(node->nodeStmt.op[0]) == execute(node->nodeStmt.op[1]);
					break;
				}
				case DIFERENTE:{
					value = execute(node->nodeStmt.op[0]) != execute(node->nodeStmt.op[1]);
					break;
				}
				case E:{
					value = execute(node->nodeStmt.op[0]) && execute(node->nodeStmt.op[1]);
					break;
				}
				case OU:{
					value = execute(node->nodeStmt.op[0]) || execute(node->nodeStmt.op[1]);
					break;
				}
				case NAO:{
					value = !execute(node->nodeStmt.op[0]);
					break;
				}
			}
 		}
	}	
	//apagar variaveis de escopo	
	removeLastSymbolsTable(linkedList);
	return value;
}
//implementações
	//mapeia a-zA-Z em 0-51 na table
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
		printf("Erro: variavel %c nao declarada\n", c);
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
		printf("Erro: variavel %c ja foi declarada nesse escopo\n", c);
		exit(1);
	}
}
int varExists(char c, SymbolsTable symbolsTable){
	return symbolsTable.declaredVars[getValueFromTable(c, symbolsTable)];
}

