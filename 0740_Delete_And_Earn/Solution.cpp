#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int maxPoints(int num, unordered_map<int, int>& points, unordered_map<int, int>& cache) {
	if (num == 0) return 0;
	if (num == 1) return points[1];

	if (cache.find(num) != cache.end()) return cache[num];

	int gain = points[num];
	cache[num] = max(maxPoints(num-1, points, cache), maxPoints(num-2, points, cache) + gain);
	return cache[num];
}

int Solution::deleteAndEarn(vector<int>& nums) {
	unordered_map<int, int> points, cache;
	int maxNumber = 0;
	for (const auto& iter : nums) {
		points[iter] += iter;
		maxNumber = max(iter, maxNumber);
	}
	return maxPoints(maxNumber, points, cache);
}
