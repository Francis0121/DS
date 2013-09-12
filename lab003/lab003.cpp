// Lab 303
// Name : 김성근
// Student ID : 20093267

#include "lab003.h"

// constructor
Polynomial::Polynomial(int cap) : capacity(cap)
{
	termArray = new Term[capacity];
	terms = 0;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{	// Add a new term to the end of termArray
	if(terms == capacity){
		capacity *= 2;
		Term *temp = new Term[capacity];//new array
		copy(termArray, termArray+terms, temp);
		delete[] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}

// init the polynomial
void Polynomial::InitPolynomial(const char *msg)
{
	cerr << endl << "Init Polynomial " << msg << endl;
	float coef; int exp;
	while(1){
		cerr << "Enter a term (coef, exp)" << endl;
		cin >> coef >> exp;
		if( exp == -1)
			return;
		NewTerm(coef, exp);
	}
}




// evaluate the polynomial at x=f
float Polynomial::Eval(float f)
{
	float e = 0.0;





	return e;
}

// check whether the two polynomials are the same
bool Polynomial::operator== (Polynomial &p)
{
	if(this == &p)
		return true;






	return true;
}


Polynomial Polynomial::Add(Polynomial &b)
{// Return the sum, c,  of the polynomials *this and b
	Polynomial c;
/*	int aPos = 0, bPos=0;
	while((aPos < terms) && (bPos < b.terms)){
		if((termArray[aPos].exp == b.temrArray[bPos].exp)	
	}
*/
	return c;
}		



