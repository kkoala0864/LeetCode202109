#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::numRescueBoats(vector<int> &people, int limit) {
	sort(people.begin(), people.end());

	int l = 0, r = people.size() - 1;

	int result = 0;
	int sum = 0;
	while (l < r) {
		sum = people[l] + people[r];

		++result;
		--r;
		if (sum <= limit) {
			++l;
		}
	}
	result += (l == r ? 1 : 0);
	return result;
}
