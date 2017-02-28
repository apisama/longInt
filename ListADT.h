/*
@	Written by Negdo A. Mesa
@	Long Integer ADT
@	For CS435 (Algorithm Design)
*/
#ifndef	LISTADT_H
#define LISTADT_H
#include "stdio.h"
#include "DLL.h"

class ListADT {
private:
	//implements listADT using a doubly linked list
	DLL myDLL; 
	
public:
	ListADT();
	~ListADT();
	int size()const;
	void destroy();
	
	Node* get_last()const;
	Node* get_first()const;
	Node* next_right(Node*)const;
	Node* next_left(Node*)const;
	void insert_right(int);
	void insert_left(int);
	void remove(Node*);
	bool is_first(Node*)const;
	bool is_last(Node*)const;	
	bool is_empty()const;

};

#endif