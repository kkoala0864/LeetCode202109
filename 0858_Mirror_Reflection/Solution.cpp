#include <Solution.h>
#include <iostream>

int Solution::mirrorReflection(int p, int q) {
	while (p % 2 == 0 || q % 2 == 0) {
		q /= 2;
		p /= 2;
	}
	return 1 - p % 2 + q % 2;
}
