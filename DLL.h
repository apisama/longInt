/*
@	Written by Negdo A. Mesa
@	Long Integer ADT
@	For CS435 (Algorithm Design)
*/
#ifndef DLL_H
#define DLL_H

#include <stdio.h>

struct Node{
	int value;
	Node* next, *prev;
};

class DLL{

public:
	Node* H, *T;
	//Doubly linked list contains only two methods standard in for linked lists
	bool isEmpty()const;
	int size()const;
	DLL();
	~DLL();
	
};

#endif

