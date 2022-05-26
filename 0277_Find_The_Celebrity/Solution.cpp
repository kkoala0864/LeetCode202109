#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

int Solution::findCelebrity(int n) {
	int candidate = 0;
	for (int i = 0 ; i < n ; ++i) {
		if (knows(candidate, i)) {
			candidate = i;
		}
	}

	for (int i = 0 ; i < n ; ++i) {
		if (i == candidate) continue;
		if (knows(candidate, i) || !knows(i, candidate)) return -1;
	}
	return candidate;
}

