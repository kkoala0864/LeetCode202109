#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;

int Solution::shareCandies(vector<int>& candies, int k) {
	int result = 0;
	unordered_map<int, int> flavors;

	int fc = 0;
	for (int i = 0 ; i < candies.size() ; ++i) {
		if (flavors.count(candies[i]) == 0) ++fc;
		++flavors[candies[i]];
	}

	for (int i = 0 ; i < candies.size() ; ++i) {
		--flavors[candies[i]];
		if (flavors[candies[i]] == 0) --fc;
		if (i >= k) {
			++flavors[candies[i-k]];
			if (flavors[candies[i-k]] == 1) ++fc;
		}
		if (i >= k - 1) {
			result = max(result, fc);
		}
	}
	return result;
}
