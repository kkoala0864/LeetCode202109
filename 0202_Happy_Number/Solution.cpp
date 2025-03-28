#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

bool Solution::isHappy(int n) {
	unordered_set<int> uSet;
	while (n != 1) {
		if (uSet.find(n) != uSet.end())
			return false;
		uSet.emplace(n);
		int next = 0;
		while (n > 0) {
			next += ((n % 10) * (n % 10));
			n /= 10;
		}
		n = next;
	}
	return true;
}
