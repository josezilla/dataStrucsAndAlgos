// practice with pointers

#include <iostream>
using namespace std;

int x = 25;
int *p = &x;

int main()  {
cout << p << endl;
cout << *p << endl;
cout << &p << endl;
cout << &*p << endl;
cout << *&p << endl;
}


