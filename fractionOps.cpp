// chapter 1

/*
 * Write a fractionClass which defines adding, subtraction, multiplying,
 * and dividing fractions by overloading standard operators for these 
 * operations.  Write a function method for reducing factors and over-
 * load I/O operators for input and output.
 */

// step zero:
// basic io

// step one:
// use struct or class

// step two:
// define operations on fractions

// step three:
// embed a method in the class

// step four:
// ensure the method o'erloads input fractions

// step five:
// ensure the method o'erloads ouput fractions


// step six:
// consider the user

// step seven:
// input output

// step 8
// 

// name the program and compile it using this command
// 	> gcc -o fractionOps fractionOps.cpp

// run it with 
//	> ./fractionOps


#include <iostream>
#include <string>
using namespace std;

int main ()
{
  int numerator;
  int denominator;
  string fraction;
  
  cout << "Enter numerator: ";
  cin >> numerator;
  cout << "The first value you entered is " << numerator << ".\n";
  
  cout << "Enter denominator: ";
  cin >> denominator;
  cout << "The second value you entered is " << denominator << ".\n";
  
  cout << "The resulting fraction is " << numerator << "/" << denominator<< ".\n";
  
  
  
  return 0;
}

	
