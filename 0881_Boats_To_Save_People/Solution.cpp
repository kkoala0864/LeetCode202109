#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::numRescueBoats(vector<int>& people, int limit) {
	sort(people.begin(), people.end());
	int end = people.size() - 1;
	int start = 0;
	int result = 0;
	while (start <= end) {
		int val = people[start] + people[end];
		if (val <= limit) {
			++start;
		}
		--end;
		++result;
	}
	return result;
}
