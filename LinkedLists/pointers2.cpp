// more pointers
#include <iostream>
using namespace std;

int i = 15, j, *p, *q;

// int p = (int*)i
 int *p = &i;
// int *p = 20;
// int j = 2 * *p;
// int q = &i;

int main() {
	cout << i << endl;
	cout << p << endl;
}
