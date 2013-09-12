#include<iostream>
#include<cstring>
using namespace std;

class Polynomial; // forward declaration

class Term {
friend class Polynomial;
private:
	float coef; //coefficient 계수
	int exp; //exponent 지수
};

class Polynomial {
	Term *termArray;
	int capacity;	// size of termArray
	int terms;	// number of nonzero terms

	void NewTerm(const float theCoeff, const int theExp);
	// Insert a new term into the polynomial

public:
	Polynomial(int capacity = 128);
	// construct the polynomial p(x)=0

	Polynomial Add(Polynomial &poly);
	//Return the sum of the polynomials *this and poly

	void InitPolynomial(const char *msg);
	// Initialize the polynomial

	// NEED TO IMPLEMENT
	// evaluate the polynomial *this at f and return the result
	float Eval(float f);

	// check whether the two polynomials are the same
	bool operator== (Polynomial &p);
}; 

