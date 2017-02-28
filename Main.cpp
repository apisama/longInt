/*
@	Written by Negdo A. Mesa
@	Long Integer ADT
@	For CS435 (Algorithm Design)
*/
#include <iostream>
#include <string>
#include "LongIntADT.h"


using namespace std;

//helper function for testing comparisons
void testComp(string, string, LongIntADT,LongIntADT);


int main(){

	LongIntADT x = "1237124721838876546789966545445112";
	LongIntADT y = "234143237675767676745";
	(x / y).print();
	
	int elms = 5;
	const int TEST_SIZE = 6;
	LongIntADT A,B,C,D,AX,AZ;
	string names[TEST_SIZE] = {"A","B","C","D","AX","AZ"};
	LongIntADT* elem[TEST_SIZE] = {&A,&B,&C,&D,&AX,&AZ};
	//the following assingments are nothing but the initialized function overloading operator=
	//i.e. A = "2222" is equivalent to A.initialize("2222");
	//A = "-99999999";
	A="2222";
	B = "99999999";
	C = "246813575732";
	D = "180270361023456789";
	AX = "29302390234702973402973420937420973420937420937234872349872934872893472893749287423847";
	AZ = "-98534342983742987342987339234098230498203894209928374662342342342356723423423";
	
	
	cout << "A * B:";
	(A*B).print();
	cout << endl;

	//testing LongIntADT.print();
	for(int i = 0; i < TEST_SIZE; i++ ){
		cout <<names[i] <<": ";  elem[i]->print(); cout << endl;
	}

	//testing LongIntADT.get_digit_count();
	for(int i = 0; i < TEST_SIZE; i++ ){
		cout << "Digits of"<< names[i] <<": " << elem[i]->get_digit_count()<< endl;
	}

	//testing equals_to, greather_than and less_than
	//operators ==, > and < are overloaded for this case

	for(int i = 0; i < TEST_SIZE; i++ ){
		for(int j = 0; j < TEST_SIZE; j++ ){
			testComp(names[i], names[j], *elem[i], *elem[j]);
		}
	}

	
	//making an integer equivalent of B to use over_flow() on it
	int intB = 99999999;
	cout << "Overflow of B (99999999): " << LongIntADT::over_flow(intB) <<endl;
	

	//Testing arithmetic

	LongIntADT E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,E1,E2,E3,E4;
	LongIntADT* elem2[22] = { &E, &F, &G, &H, &I, &J, &K, &L, &M, &N, &O, &P, &Q, &R, &S, &T, &U, &V, &E1, &E2, &E3, &E4 };
	string op[22] = {		
		" E = A + D"," F = B + C"," G = C + D"," H = E + E"," I = A + E"," J = B + G", 
		" K = A - D"," L = C - D"," M = D - C"," N = H - H"," O = L - K"," P = J - M",
		" Q = A * D"," R = B * C"," S = D * D"," T = K * E"," U = F * L"," V = I * J",
		" E1 = AX * AZ", "E2 = AX * AX", "E3 = AZ * AZ", "E4 = E2 * E3"
	};

	E = A + D; F = B + C; G = C + D; H = E + E; I = A + E; J = B + G; 
	K = A - D; L = C - D; M = D - C; N = H - H;	O = L - K; P = J - M; 
	Q = A * D; R = B * C; S = D * D; T = K * E; U = F * L; V = I * J;
	E1 = AX * AZ; E2 = AX * AX;  E3 = AZ * AZ; E4 = E2 * E3;

	for(int i = 0; i < 22; i++ ){
		cout << op[i] <<" = "; elem2[i]->print(); cout<< endl;
	}
	
	LongIntADT W,X,Y,Z,AA,AB,E5,E6,E7,E8;
	LongIntADT* elem3[10] = { &W,&X,&Y,&Z,&AA,&AB,&E5,&E6,&E7,&E8};
	W = D ^ 2; X = A ^ 5; Y = B ^ 10; Z = W ^ 4; AA = E ^ 2; AB = K ^ 2;
	E5 = AX ^ 10; E6 = AZ ^ 14; E7 = E2 ^ 4; E8 = E3 ^ 7; 
	string op2[10] = {		
		"W = D ^ 2",  "X = A ^ 5", "Y = B ^ 10",  "Z = W ^ 4",  "AA = E ^ 2", " AB = K ^ 2",
		"E5 = AX ^ 10", "E6 = AZ ^ 14", "E7 = E2 ^ 4", "E8 = E3 ^ 7"
	};
	for(int i = 0; i < 10; i++ ){
		cout << op2[i] <<" = "; elem3[i]->print(); cout<< endl;
	}
	
	LongIntADT AC, AD, AE, AF, AG, AH;
	LongIntADT* elem4[6] = { &AC, &AD, &AE, &AF, &AG, &AH };
	W = D ^ 2; X = A ^ 5; Y = B ^ 10; Z = W ^ 4; AA = E ^ 2; AB = K ^ 2;
	E5 = AX ^ 10; E6 = AZ ^ 14; E7 = E2 ^ 4; E8 = E3 ^ 7;
	string op3[6] = {
		"AC = D / B", "AD = D / A", "AE = Q / D", "AF = T / K", "AG = H / E", "AH = U / U "
	};

	AC = D / B; AD = D / A; AE = Q / D;
	AF = T / K;
	AG = H / E;
	AH = U / U;

	for (int i = 0; i < 6; i++){
		cout << op3[i] << " = "; elem4[i]->print(); cout << endl;
	} 

	LongIntADT A1, A2;
	A1 = "2456883200";
	A2 = "2822356";
	cout<<"A1 / A2 = "; 
	(B/A).print();
	cout<<endl;
	return 0;
}


void testComp(string namea, string nameb, LongIntADT A, LongIntADT B){
	
	cout << namea << " == " << nameb <<  " is " << boolalpha << (A == B) << endl;
	cout << namea << " > " << nameb << " is " << boolalpha << (A > B) << endl;
	cout << namea << " < " << nameb << " is " << boolalpha << (A < B) << endl;
	cout<<noboolalpha<<endl;
}

