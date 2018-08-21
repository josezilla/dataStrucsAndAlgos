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
// 	> reset && gcc -o fractionOps fractionOps.cpp

// run it with 
//	> ./fractionOps


#include <iostream>
#include <string>
using namespace std;

int main ()
{

  int numerator;
  int denominator;
  string fraction1;
  string notFraction;
  int operation;
  
  cout << "Enter numerator: ";
  cin >> numerator;
  cout << "The first value you entered was " << numerator << ".\n";
  
  cout << "Enter denominator: ";
  cin >> denominator;
  cout << "The second value you entered was " << denominator << ".\n";
  
  // put stuff into the fraction variable so that it is clean
  fraction1 = "\n"+ to_string(numerator)+  "/" + to_string(denominator)+ "\n";
  notFraction = to_string(numerator)+  "/" + to_string(denominator)+" is a whole number... try again!\n\a";
  
  if (numerator!=denominator)
  {
	  cout << fraction1;
	  cout << "What operation do you want to perform on these fractions?\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Abort\n\n";
	  cin >>  operation;
	  
	  switch (operation) {
	  case 1:
		cout << "Addition\n";
		break;
	  case 2:
		cout << "Subtraction\n";
		break;
	  case 3:
		cout << "Multiplication\n";
		break;
	  case 4:
		cout << "Division\n";
		break;
	  default:
		cout << "Abort\n";
	  }
  } else {
	  cout << notFraction;
	  }
  
  
  
  return 0;
}

	
