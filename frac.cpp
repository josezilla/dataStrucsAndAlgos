// fractionClass.cpp

#include <iostream>
#include <string>
using namespace std;

class Fraction {
	public:
		double getFrac(void) {
			return numerator / denominator;
		}
		void setNumerator(double numer) {
			numerator = numer;
		}
		void setDenominator(double denom) {
			denominator = denom;
		}
	
	// overload + (plus) operator to add two Fraction objects
	Fraction operator+(const Fraction& f) {
		Fraction fraction;
		fraction.numerator = ((this->numerator)*(f.denominator)) + ((f.numerator)*(this->denominator));
		fraction.denominator = (this->denominator)*(f.denominator);
		return fraction;
		}

	// overload - (minus) operator to add two Fraction objects
	Fraction operator-(const Fraction& f) {
		Fraction fraction;
		fraction.numerator = ((this->numerator)*(f.denominator)) - ((f.numerator)*(this->denominator));
		fraction.denominator = (this->denominator)*(f.denominator);
		return fraction;
		}
	
	public:
		double numerator;
		double denominator;
};

int main() {
	// using the class to instantiate fractions
	Fraction fraction1;
	Fraction fraction2;
	Fraction fraction3;
	double result = 0.0;


	
	// fraction1 specification.....
	fraction1.setNumerator(9);
	fraction1.setDenominator(8);	
	// fraction2 specification.....
	fraction2.setNumerator(7);
	fraction2.setDenominator(12);

		cout << "*************  - FRACTIONS -  *************" << endl;
	// result of fraction1
	result = fraction1.getFrac();
	cout << "First fraction: " << result << endl;
	cout << fraction1.numerator << "/" << fraction1.denominator << "\n";	
	// result of fraction2
	result = fraction2.getFrac();
	cout << "\nSecond fraction: " << result << endl;
	cout << fraction2.numerator << "/" << fraction2.denominator << "\n";

	cout << "************* MATH OPERATIONS *************" << endl;
	// add fracs
	cout << "\n*****addition*****" << endl;
	fraction3 = fraction1 + fraction2;
	result = fraction3.getFrac();
	cout << "sum of the two fractions: " << result << endl;
	cout << "OR...\n"<< fraction3.numerator << "/" << fraction3.denominator << "\n";
	
	// subtract fracs
	cout << "\n***** subtraction *****" << endl;
	fraction3 = fraction1 - fraction2;
	result = fraction3.getFrac();
	cout << "difference of the two fractions: " << result << endl;
	cout << "OR...\n"<< fraction3.numerator << "/" << fraction3.denominator << "\n";


	return 0;
}
