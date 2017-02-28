/*
@	Written by Negdo A. Mesa
@	Long Integer ADT
@	For CS435 (Algorithm Design)
*/
#include "LongIntADT.h"

 const int LongIntADT::DIGIT_S = 4;
 const int LongIntADT::BASE_TEN = 10;
 const int LongIntADT::BASE_LONGINT = 10000;
 const int LongIntADT::MAX_DIGIT = BASE_LONGINT - 1;


LongIntADT::LongIntADT() : sign(false){}

LongIntADT::LongIntADT(string s): sign(false){
	
	initialize(s);
}
//copy constructor
LongIntADT::LongIntADT(const LongIntADT& other){
	if(other.list.is_empty()){ 
		return;
	}
	sign = other.sign;
	Node* p_list = other.list.get_first();
	for(int i = 0;i < other.list.size();i++){
		list.insert_right(p_list->value);
		p_list = other.list.next_right(p_list);

	}
	
}
//assignment operator

LongIntADT& LongIntADT::operator= (const LongIntADT& other) {
	if(!other.list.is_empty()){
		if(!list.is_empty()){
			list.destroy();
		}
		sign = other.sign;
		Node* p_list = other.list.get_first();
		for(int i = 0;i < other.list.size();i++){
			list.insert_right(p_list->value);
			p_list = other.list.next_right(p_list);

		}
	}
	return *this;	

}
//overloaded operators just redirect their action to the 
//respective functions
LongIntADT& LongIntADT::operator= (const string& s) {
	initialize(s);
	return *this;
}

LongIntADT& LongIntADT::operator= (int i) {
	int temp;
	if(!list.is_empty()){
		list.destroy();
	}
	
	while(i){
		temp = over_flow(i);
		list.insert_left(i);
		i = temp;
	}
	sign = false;//assuming int i is always positive
	return *this;
}
bool LongIntADT::operator== (const LongIntADT& other)const{
	return this->equal_to(other);
}
bool LongIntADT::operator> (const LongIntADT& other)const{
	return this->greater_than(other);
}
bool LongIntADT::operator< (const LongIntADT& other)const{
	return this->less_than(other);
}
const LongIntADT LongIntADT::operator+(const LongIntADT& other) const{
	return this->add(other);
}
const LongIntADT LongIntADT::operator-(const LongIntADT& other) const{
	return this->subtract(other);
}
const LongIntADT LongIntADT::operator*(const LongIntADT& other) const{
	return this->multiply(other);
}
const LongIntADT LongIntADT::operator/(const LongIntADT& other) const{
	return this->divide(other);
}

const LongIntADT LongIntADT::operator+(int i) const{
	LongIntADT l_int;
	l_int = i;
	return this->add(l_int);
}
const LongIntADT LongIntADT::operator-(int i) const{
	LongIntADT l_int;
	l_int = i;
	return this->subtract(l_int);
}
const LongIntADT LongIntADT::operator*(int i) const{
	LongIntADT l_int;
	l_int = i;
	return this->multiply(l_int);
}
const LongIntADT LongIntADT::operator^(int p) const{
	return power(p);

}



void LongIntADT::initialize(string s){
	if (!list.is_empty()){
		list.destroy();
	}
	if (!parse(s)){
		return;
	} 
	
	fill(s);
	stli(s);
}

bool LongIntADT::parse(string& s){
	if (s.empty()){
		return false;
	}
	if (s[0] == '-' || s[0] == '+'){
		set_sign(s[0]);
		s.erase(0,1);
	}
	string temp;

	for (string::iterator itr = s.begin();itr != s.end();itr++){
		if (isdigit(*itr)){
			temp.push_back(*itr);
		}
	}
	if (temp.empty()){
		return false;
	}
	s = temp;
	return true;
}
void LongIntADT::fill(string& s)const{
	int digits =  DIGIT_S - (s.length() % DIGIT_S) ;
	if (digits == DIGIT_S){
		return;
	}
	while (digits > 0){
		s.insert(0, "0");
		digits--;
	}
	
}


void LongIntADT::stli(string& s){
	int count = s.length() / DIGIT_S;
	for (int i = 0; i < count; i++){
		string sstr = s.substr(i * DIGIT_S, DIGIT_S);
		list.insert_right(StringToNumber<int>(sstr));
	}
}

char LongIntADT::get_sign()const{
	return sign ? '-' : '+';
}
void LongIntADT::set_sign(char c){
	if (c == '-'){
		sign = true;
	}
	else if (c == '+'){
		sign = false;
	}
	

}
int LongIntADT::get_digit_count() const{
	//Counting digits is a matter of 
	//multiplying number of nodes 
	//by digits harbored by each node
	//However, the first node might not have full digits
	//therefore it must be counted separately
	int count = (list.size()-1)*DIGIT_S;
	count += digit(list.get_first()->value);
	return count;
}

void LongIntADT::print()const{
	if (list.is_empty()){
		cout << "empty"<<endl;
		return;
	}
	string s,t_s;
	s.reserve(get_digit_count()+1);
	if (sign){
		s.push_back('-');
	}
	Node* X = list.get_first();
	
	
	while (!list.is_last(X)){
		t_s = NumberToString<int>(X->value);
		if (!list.is_first(X))
			fill(t_s);//print leading zeroes on intermediate and rightmost nodes
		s += t_s;
		X = list.next_right(X);
	}
	t_s = NumberToString<int>(X->value);
	if (!list.is_first(X)){
		fill(t_s);//print leading zeroes on intermediate and rightmost nodes
	}
	s += t_s;
	cout << s;
}

void LongIntADT::sanitize(){
	Node* t_ptr;
	Node* n_ptr = list.get_first();
	while(n_ptr->value == 0 && !list.is_last(n_ptr) ){
		t_ptr = list.next_right(n_ptr);
		list.remove(n_ptr);
		n_ptr = t_ptr;
	}

}
int LongIntADT::digit(int d){
	if (!d){
		return 1;
	}
	int count = 0;
	while (d > 0){
		d = d / BASE_TEN;
		count++;
	}
	return count;
}
int LongIntADT::over_flow(int& num){
	
	if (digit(num)> DIGIT_S){
		int temp;
		temp = num/BASE_LONGINT;
		num = num % BASE_LONGINT;
		return temp;
	}
	else
		return 0;
}



bool LongIntADT::greater_than(const LongIntADT& other)const{
	//fist checks if its equal by using equal_to()
	if (*this == other){
		return false;
	}
	//if they both have different sign the answer is straightforward
	//if same sign then we'll look who's list is bigger
	//If they have equal sized list, then what's left is compare the value of the first node
	/*UPDATE: There is an error in the previous mentioned logic, since same sized integers that also have same 
	first node will give incorrect results. Fixed by comparing each long digit from left to right*/
	
	if (sign == other.sign){
		
		if (list.size() == other.list.size()){
		
			Node* X = list.get_first();
			Node* Y = other.list.get_first();
			for(int i = 0;i < list.size();i++, X = list.next_right(X), Y = other.list.next_right(Y)){
				if(X->value > Y->value){
					return !sign;
				}
				else if(X->value < Y->value){
					return sign;
				}
				
			}
			return false;
		}
		else if (list.size() > other.list.size()){
			return !sign;
		}
		else return sign;
	}
	else {
		return !sign;
	}
	
}


bool LongIntADT::less_than(const LongIntADT& other)const{
	//check if they are equal
	if (*this == other){
		return false;
	}
	//if not equal, then just invert the results of greater_than
	return !(*this > other);
}
bool LongIntADT::equal_to(const LongIntADT& other)const {
	//check if they have the same sign, otherwise they're different
	if (sign == other.sign){
		//check if their lists have the same size
		if (list.size() == other.list.size()){
			//the plot thickens...
			//traverse each node and check whether the values in it are equal
			Node* a,* b;
			a = list.get_first();
			b = other.list.get_first();
			for (int i = 0; i < list.size(); i++){
				if (a->value != b->value){
					return false;
				}
				a = list.next_right(a);
				b = list.next_right(b);
			}
			return true;
		}
	}
	return false;
}

const LongIntADT LongIntADT::longAbs()const{
	LongIntADT result = (*this);
	result.set_sign('+');
	return result;
}
const LongIntADT LongIntADT::add(const LongIntADT& other)const{
	
	LongIntADT result;
	if(sign == other.sign){//if they have same sign
		int addVal, carry;
		Node* ls, *rs;
		ls = list.get_last();
		rs = other.list.get_last();
		addVal = ls->value + rs->value;
		carry = LongIntADT::over_flow(addVal);
		result.list.insert_left(addVal);
		while(!list.is_first(ls) && !other.list.is_first(rs)){
			ls = list.next_left(ls);
			rs = other.list.next_left(rs);
			addVal = ls->value + rs->value + carry;
			carry = LongIntADT::over_flow(addVal);
			result.list.insert_left(addVal);
		
		}

		if(list.is_first(ls)){
			
			while(!other.list.is_first(rs)){
				rs = other.list.next_left(rs);
				addVal = rs->value + carry;
				carry = LongIntADT::over_flow(addVal);
				result.list.insert_left(addVal);
			}
								
		}
		else if (other.list.is_first(rs)){
			while (!list.is_first(ls)){
				ls = other.list.next_left(ls);
				addVal = ls->value + carry;
				carry = LongIntADT::over_flow(addVal);
				result.list.insert_left(addVal);
			}
		}

		if (carry){
			result.list.insert_left(carry);
		}
		result.sign = sign;


	}
	else{ //if they have opposite signs
		LongIntADT lsABS = (*this).longAbs(), rsABS = other.longAbs();
		if (lsABS == rsABS){
			result = "0";		
		}
		else if (lsABS > rsABS){
			result = (lsABS - rsABS);
			result.set_sign((*this).get_sign());
		}
		else{
			result = (rsABS - lsABS);
			result.set_sign(other.get_sign());
		}
	}
	return result;
}

const LongIntADT LongIntADT::subtract(const LongIntADT& other) const{
	LongIntADT result;
	
	if(this->sign == other.sign){//if they both have same sign
		if((*this) == other){
			return result = "0";
		}

		const LongIntADT *max,*min;
		if(this->longAbs() > other.longAbs()){
			max = this;
			min = &other;
		}
		else{
			max = &other;
			min = this;		
		}
		Node *ls, *rs;
		ls = max->list.get_last();
		rs = min->list.get_last();

		int subVal, carry, t_ls;

		t_ls = ls->value;
		if(rs->value > ls->value){
			t_ls = ls->value + BASE_LONGINT;
		}

		subVal = t_ls - rs->value;
		carry = LongIntADT::over_flow(t_ls);
		result.list.insert_left(subVal);
		while(!max->list.is_first(ls) && !min->list.is_first(rs)){
			ls = max->list.next_left(ls);
			rs = min->list.next_left(rs);
			t_ls = ls->value;
			if(rs->value+carry > ls->value){
				t_ls = ls->value + BASE_LONGINT;
			}

			subVal = t_ls - (rs->value + carry);
			carry =  LongIntADT::over_flow(t_ls);
			result.list.insert_left(subVal);
		}

		while(!max->list.is_first(ls)){
			ls = max->list.next_left(ls);
			t_ls = ls->value;
			if (carry > ls->value){
				t_ls = ls->value + BASE_LONGINT;	
			}
			subVal = t_ls - carry;
			result.list.insert_left(subVal);
			carry = LongIntADT::over_flow(t_ls);

		}
		result.list.insert_left(carry);
		result.sanitize();
		if(max == &other){
			result.sign = !max->sign;
		}else{
			result.sign = max->sign;
		}
		
		
	}else{//if they have signs opposite of eachother
		result = (this->longAbs() + other.longAbs());
		result.sign = this->sign;
	}
	return result;
}
const LongIntADT LongIntADT::multiply(const LongIntADT& other)const{
	LongIntADT result;
	int multVal, carry;
	if (this->sign == other.sign){
		result.set_sign('+');
	}
	else{
		result.set_sign('-');
	}

	Node* ls, *rs, *curr_node;
	ls = this->list.get_last();
	rs = other.list.get_first();
	carry = 0;
	for(int i = 0; i < this->list.size();i++){
		multVal = (ls->value * rs->value) + carry;
		carry = LongIntADT::over_flow(multVal);
		result.list.insert_left(multVal);
		ls = this->list.next_left(ls);
	}

	if(carry){
		result.list.insert_left(carry);
	}
	
	while(!other.list.is_last(rs)){
		ls = this->list.get_last();//reset ls pos
		rs = other.list.next_right(rs);//move rs pos
		result.list.insert_right(0);
		carry = 0;
		curr_node = result.list.get_last();//should be node containing zeroes
		for(int i = 0; i < this->list.size();i++){
			multVal = (ls->value * rs->value) + carry;
			curr_node->value += multVal;
			carry = LongIntADT::over_flow(curr_node->value);
			curr_node = result.list.next_left(curr_node);
			ls = this->list.next_left(ls);
		}

		while(carry){
			curr_node->value += carry;
			carry = LongIntADT::over_flow(curr_node->value);
			/*Check if we ran out of nodes*/
			if(other.list.is_first(curr_node)){
				result.list.insert_left(0);
				
			}
			curr_node = other.list.next_left(curr_node);
		}

		

	}
	
	result.sanitize();//remove leading zeroes


	return result;
}


int LongIntADT::extract_int_front(const LongIntADT& lint, int digits)const{
	int result;
	if(digits > 9){
		return -1;
	}
	Node* node_ptr;
	node_ptr = lint.list.get_first();
	result = node_ptr->value;
	while(LongIntADT::digit(result) < digits){
		node_ptr = lint.list.next_right(node_ptr);
		result *= BASE_LONGINT;
		result += node_ptr->value;
	}
	while(LongIntADT::digit(result) != digits){
		result /= BASE_TEN;

	}
	return result;
}

const LongIntADT LongIntADT::divide(const LongIntADT& other)const{
	LongIntADT result, remainder, temp, denominator;
	int n, d, q, size, padding,prev_padding;
	if (other == LongIntADT("0")){
		exit(1); //division by zero is bad man
	}

	remainder = this->longAbs();
	denominator = other.longAbs();
	
	if (remainder < denominator){
		return result ="0";//if denominator is bigger than numerator return 0
	}
	else if (remainder == denominator){//if equal return 1
		return result = "1";
	}

	result = "0";
	
	//initial padding and prev_padding
	padding = 1;//is set to one so we can enter the while loop.
	prev_padding = 0;
	//extract initial denominator (max 4 digits)
	size = other.get_digit_count();
	if (size > 4){
		size = 4;
		d = denominator.extract_int_front(denominator, size);
		if (d < 0){
			exit(1);//error 
		}
	}
	else{
		d = denominator.extract_int_front(denominator, size);
		if (d < 0){
			exit(1);//error 
		}
	}
	while (remainder > denominator || padding > 0){
		
		//extract integer numerator from long integer numerator

		if ((n = extract_int_front(remainder, size)) < 0){
			exit(1);//error of some sort
		}

		//make sure numerator is not samller than denominator
		if (d > n){
			n = extract_int_front(remainder, (size + 1));
		}
		q = n / d;//quotient

		temp = denominator * q;
		//calculate amount of zeroes padding
		padding = remainder.get_digit_count() - temp.get_digit_count();
		
		
		//match length of previous remainder by padding zeroes
		if (padding){
			for (int i = 0; i < padding; i++){
				temp = temp * BASE_TEN;
			}
		}
		//check that remainder is greater, shift to the right (removing the rightmost zero)
		if (remainder < temp){
			temp = denominator * q;
			for (int i = 0; i < (padding - 1); i++){
				temp = temp * BASE_TEN;
			}
			//adjust padding value
			padding--;
		}

		//each iteration the remainder is reduced by one
		//if that's not the case, it means the reduction is implied and zeroes are added to the quotient
		while (padding < (prev_padding - 1)){
			prev_padding--;
			result = (result * BASE_TEN);
		}

		//calculate current remainder and current quotient
		remainder = remainder - temp;
		result = (result * BASE_TEN) + q;
		//keep track of this iteration's padding value
		prev_padding = padding;
	}
	
	//setting signs
	if(this->sign == other.sign){
		result.sign = false; //same signs, quotient is positive
	}else{
		result.sign = true; // different signs, quotient is negative
	}
	return result;
}

const LongIntADT LongIntADT::power(int p)const{
	LongIntADT result, base;
	base = *this;//power is immutable, so must make a copy of the base to ease calculations
	result = "1";//if p = 0 then result is 1
	if (p < 0){
		p = 0;
	}
	while(p){
		if(p & 1){
			result = result * base;
		}
		p >>= 1;
		base = base * base; //square base each shift
	
	}
	return result;
}
		
