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
	
	// overload + operator to add two Fraction objects
	Fraction operator+(const Fraction& f) {
		Fraction fraction;
		fraction.numerator = this->numerator + f.numerator;
		fraction.denominator = this->denominator;// + f.denominator;
		return fraction;
		}
	
	public:
		double numerator;
		double denominator;
};

int main() {
	Fraction fraction1;
	Fraction fraction2;
	Fraction fraction3;
	double result = 0.0;
	
	// fraction1 specification
	fraction1.setNumerator(9);
	fraction1.setDenominator(8);
	
	// fraction2 specification
	fraction2.setNumerator (9);
	fraction2.setDenominator(8);
	
	// result of fraction1
	result = fraction1.getFrac();
	cout << "\nFirst fraction: " << result << endl;
	cout << fraction1.numerator << "/" << fraction2.denominator << "\n";
	
	// result of fraction2
	result = fraction2.getFrac();
	cout << "\nSecond fraction: " << result << endl;
	cout << fraction2.numerator << "/" << fraction2.denominator << "\n";

	// add fracs
	fraction3 = fraction1 + fraction2;

	result = fraction3.getFrac();
	cout << "\nsum of the two fractions: " << result << endl;
		cout << "OR...\n";
		cout << fraction3.numerator << "/" << fraction3.denominator << "\n";
	
	// subtract fracs
	// multipy fracs
	// divide fracs

	return 0;
}
