/*
@	Written by Negdo A. Mesa
@	Long Integer ADT
@	For CS435 (Algorithm Design)
*/
#include "DLL.h"

DLL::DLL(){
	H = NULL;
	T = NULL;
}
DLL::~DLL(){
	//H = NULL;
	//T = NULL;
}

bool DLL::isEmpty()const{
	return H == NULL ? true: false;
}

int DLL::size()const{
	int count = 0;
	Node* X = H;
	while (X != NULL){
		X = X->next;
		count++;
	}
	return count;
}
