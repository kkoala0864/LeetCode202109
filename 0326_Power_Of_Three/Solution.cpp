#include <Solution.h>
#include <iostream>
#include <cmath>
/*
bool Solution::isPowerOfThree(int n) {
        if (n <= 0) return false;
        while ( n > 1 ) {
                if (n % 3) return false;
                if (n /= 3;
        }
        return true;
}
*/

bool Solution::isPowerOfThree(int n) {
	int val = pow(3, 19);
	return n > 0 ? (val % n) == 0 : false;
}
