#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<bool> Solution::kidsWithCandies(vector<int> &candies, int extraCandies) {
	int mv = 0;
	for (const auto &v : candies)
		mv = max(mv, v);
	vector<bool> result;
	for (const auto &v : candies) {
		result.emplace_back((v + extraCandies) >= mv);
	}
	return result;
}
