#include <stdio.h>
#include <stdlib.h>
//constantes
const int symbolsNumber = 52;
//estruturas
typedef struct {
	int table[52];	
	int declaredVars[52];
} SymbolsTable;
typedef struct node_t {
	struct node_t *next;
	struct node_t *before;
	SymbolsTable symbolsTable;
} Node;
typedef struct {
	Node first;
	Node *last;
	int size;
} LinkedList;
//metodos
LinkedList * createLinkedList (){
	LinkedList *linkedList;
	linkedList = (LinkedList*) malloc(sizeof(LinkedList));
	linkedList->first.before = &linkedList->first;
	linkedList->first.next = &linkedList->first;
	linkedList->last = NULL;
	linkedList->size = 0;
	return linkedList;
}
void addSymbolsTable(LinkedList *linkedList){
	if (linkedList->size == 0){
		linkedList->last = (Node*) malloc(sizeof(Node));
		linkedList->first.next = linkedList->last;
	}else{
		linkedList->last->next = (Node*) malloc(sizeof(Node));
		linkedList->last->next->next = &linkedList->first;
		linkedList->last->next->before = linkedList->last;
		linkedList->last = linkedList->last->next;
	}
	linkedList->first.before = linkedList->last;
	linkedList->size++;
}
void removeLastSymbolsTable(LinkedList *linkedList){
	if (linkedList->size > 0){
		Node *toRemove = linkedList->last;
		linkedList->last = linkedList->last->before;
		linkedList->last->next = &linkedList->first;
		linkedList->first.before = linkedList->last;
		linkedList->size--;
		free(toRemove);
	}
}
SymbolsTable * getSymbolsTable(LinkedList *linkedList, int index){
	if (index >= linkedList->size || index < 0){
		printf("Erro: %d indice fora do limite da lista.\n", index);
		exit(1);
	}
	if (linkedList->size == 0){
		return NULL;	
	}
	int i;
	Node *node;	
	node = linkedList->first.next;
	for (i = 0; i < index && node->next != &linkedList->first; i++){
		node = node->next;	
	}
	return &node->symbolsTable;
}
