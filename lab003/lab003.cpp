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

	for(int i=0; i< terms ; i++){
		float theCoef = termArray[i].coef;
		int theExp = termArray[i].exp;
		if(!theExp){
			e += theCoef;		
		}else{
			float mul = 1;
			for(int j=0; j< theExp; j++){
				mul *= f;	
			}
			mul *= theCoef;
			e += mul;
		}
	}

	return e;
}

// check whether the two polynomials are the same
bool Polynomial::operator== (Polynomial &p)
{
	if(this == &p)
		return true;

	if(terms != p.terms )
		return false;		

	int pos=0;
	while(pos < terms){
		if(termArray[pos].exp != p.termArray[pos].exp){
			return false;
		}else{
			if(termArray[pos].coef != p.termArray[pos].coef){
				return false;
			}else{	
				pos++;
			}
		}
	}

	return true;
}


Polynomial Polynomial::Add(Polynomial &b)
{// Return the sum, c,  of the polynomials *this and b
	Polynomial c;
	int aPos = 0, bPos=0;
	while((aPos < terms) && (bPos < b.terms)){
		if((termArray[aPos].exp == b.termArray[bPos].exp)){
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if(t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}else if((termArray[aPos].exp < b.termArray[bPos].exp)){
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}else{
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	}
	// add in remaining term of *this and b
	for(; aPos < terms; aPos++){
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);	
	}
	for(; bPos < b.terms; bPos++){
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	}
	
	return c;
}		



