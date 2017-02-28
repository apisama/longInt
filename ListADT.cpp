/*
@	Written by Negdo A. Mesa
@	Long Integer ADT
@	For CS435 (Algorithm Design)
*/
#include "ListADT.h"


ListADT::ListADT(){

}

ListADT::~ListADT(){
	destroy();
}

void ListADT::destroy(){
	Node* X = myDLL.H;
	Node* Y;
	if (X == NULL){
		return;
	}
	while (X != NULL){
		Y = X->next;
		remove(X);
		X = Y;
	}
}

int ListADT::size()const{
	return myDLL.size();
}

Node* ListADT::get_last()const{
	
	return myDLL.T;
}
Node* ListADT::get_first()const{
	
	return myDLL.H;
}
Node* ListADT::next_right(Node* n)const{
	if(myDLL.isEmpty()){
		return NULL;
	}
	return n->next;
}
Node* ListADT::next_left(Node* n)const{
	if(myDLL.isEmpty()){
		return NULL;
	}
	return n->prev;
}
void ListADT::insert_right(int val){
	Node* newNode = new Node;
	newNode->value = val;
	if(myDLL.isEmpty()){
		myDLL.T = newNode;
		myDLL.H = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else{
		myDLL.T->next = newNode;
		newNode->prev = myDLL.T;
		newNode->next = NULL;
		myDLL.T = newNode;
	}
}
void ListADT::insert_left(int val){
	Node* newNode = new Node;
	newNode->value = val;
if(myDLL.isEmpty()){
		myDLL.T = newNode;
		myDLL.H = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else{
		myDLL.H->prev = newNode;
		newNode->next = myDLL.H;
		newNode->prev = NULL;
		myDLL.H = newNode;
	}
}
void ListADT::remove(Node* X){
	if (X==NULL) return; 

	if (myDLL.H == myDLL.T && X == myDLL.H){
		myDLL.H = NULL;
		myDLL.T = NULL;
		
	}
	else if (X == myDLL.H){
		Node* temp = X->next;
		temp->prev = NULL;
		myDLL.H = temp;
		
	}
	else if (X == myDLL.T){
		Node* temp = X->prev;
		temp->next = NULL;
		myDLL.T = temp;
		
	}
	else {
		Node* p = X->prev;
		Node* n = X->next;
		p->next = n;
		n->prev = p;
		
	}
	delete X;
}

bool ListADT::is_first(Node* n)const{
	return myDLL.H == n? true : false;
}
bool ListADT::is_last(Node* n)const{
	return myDLL.T == n? true : false;
}

bool ListADT::is_empty()const{
	return myDLL.isEmpty();
}