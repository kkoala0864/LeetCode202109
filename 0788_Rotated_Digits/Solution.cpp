#include <Solution.h>
#include <iostream>

int Solution::rotatedDigits(int n) {
	int result = 0;
	for (int i = 1 ; i <= n ; ++i) {
		int cur = i;
		int flag = false;
		int j = 0;
		for (; j < 5 ; ++j) {
			int mod = cur % 10;
			if (mod == 3 || mod == 4 || mod == 7) break;
			if (mod == 2 || mod == 5 || mod == 6 || mod == 9) flag = true;
			cur /= 10;
		}
		if (j != 5) continue;
		if (flag) ++result;
	}
	return result;
}
