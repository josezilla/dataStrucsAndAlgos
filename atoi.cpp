// convert ascii character string to an integer

//#include <iostream>
//using namespace std;
#include <stdio.h>

int myAtoI(char *str) {
        int res = 0;
        int sign = 1;
        int i = 0;
        // if number is negative, update sign
        if (str[0] == '-') {
                sign = -1;
                i++;
        }

        for (; str[i] != '\0'; ++i)
                res = res*10 + str[i] - '0';
        return sign * res;
}

int main() {
        char str1[] = "1234";
        char str2[] = "12340000";
        int val1 = myAtoI(str1);
        int val2 = myAtoI(str2);
        printf ("%d\n", val1 + val2);
        return 0;
}

