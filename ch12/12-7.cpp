// poninersonc12-7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct SNODE {
	struct SNODE *next;
	char value[15];
}SNode;
typedef struct CNODE {
	struct CNODE *next;
	char value;
	struct SNODE *snode;
}CNode;
CNode* GetCNode(CNode** linkp, char ch) {
	CNode *current = *linkp;
	while ((current=*linkp)!= NULL&&current->value<ch) {
		linkp = &current->next;	
	}
	if (current != NULL&&current->value == ch) {
		return current;
	}
	CNode* newnode = (CNode *)malloc(sizeof(CNode));
	newnode->value = ch;
	newnode->next = current;
	newnode->snode = NULL;
	*linkp = newnode;
	return newnode;
}
int insert(CNode** cn, char *ss) {
	char val = ss[0];
	if (!islower(val))
		return 0;
	CNode *cnode = GetCNode(cn, val);
	//SNode *snode = cnode->snode;
	SNode **link = &cnode->snode;
	SNode *current = *link;
	while ((current=*link) != NULL&&strcmp(current->value, ss)<0) {
		link = &current->next;
	}
	if (current != NULL&&strcmp(current->value, ss) == 0)
		return 0;
	SNode *newnode = (SNode*)malloc(sizeof(SNode));
	strcpy(newnode->value, ss);
	newnode->next = current;
	*link = newnode;
	return 1;
}
void printCNode(CNode* cn) {
	CNode *cnode = cn;
	SNode *snode;
	while (cnode != NULL) {
		snode = cnode->snode;
		printf("character %c: ", cnode->value);
		while (snode != NULL) {
			printf("%s ", snode->value);
			snode = snode->next;
		}
		cnode = cnode->next;
		printf("\n");
	}
}
int main() {
	CNode* cnode = NULL;
	insert(&cnode, "hello");
	insert(&cnode, "hi");
	insert(&cnode, "world");
	insert(&cnode, "aaa");
	insert(&cnode, "aa");
	insert(&cnode, "nihao");
	printCNode(cnode);
}



