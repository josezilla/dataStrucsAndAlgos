// fractionClass.cpp

#include <iostream>
#include <string>
using namespace std;

class Fraction {
	public:
		double numerator;
		double denominator;
};

int main() {
	Fraction fraction1;
	Fraction fraction2;
	double result = 0.0;
	
	fraction1.numerator = 9;
	fraction1.denominator = 8;
	
	fraction2.numerator = 7;
	fraction2.denominator = 6;
	
	result = fraction1.numerator / fraction1.denominator;
	cout << "\nFirst fraction: " << result << endl;
	cout << to_string(int(fraction1.numerator))+  "/" + to_string(int(fraction1.denominator))+ "\n";
	
	result = fraction2.numerator / fraction2.denominator;
	cout << "\nSecond fraction: " << result << endl;
	cout << to_string(int(fraction2.numerator))+  "/" + to_string(int(fraction2.denominator))+ "\n";


	return 0;
}
