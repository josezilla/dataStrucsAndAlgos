// more pointers
#include <iostream>
using namespace std;


int main() {
	int i = 15, j, *p, *q;

	p = &i; // p is a pointer that holds the address of i
	*p = 20; // assign 20 to the variable pointed to by p
	j = 2 * *p;
	q = &i;
	*p = *q-1;
	q = &j;
	*p = *q + 1;
	
	cout << p << endl; 
	cout << i << endl; 
	cout << j << endl;
	cout << q << endl; 
	cout << *p << endl;
	cout << q << endl;
	cout << *p << endl;
	
	return 0;
}

/*
0x7ffd78a3b700
41
40
0x7ffd78a3b704
41
0x7ffd78a3b704
41
 */
