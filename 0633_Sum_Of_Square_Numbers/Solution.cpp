#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <cmath>

using std::unordered_set;

bool Solution::judgeSquareSum(int c) {
	unordered_set<int> us;
	int limit = sqrt(c);
	for (int i = 0; i <= limit; ++i) {
		us.emplace(i * i);
		if (us.count(c - i * i))
			return true;
	}
	return false;
}
