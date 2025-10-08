#include <Solution.h>

vector<int> Solution::successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
	sort(potions.begin(), potions.end());

	vector<int> result;
	int size = potions.size();
	for (const auto& s : spells) {
		long long target = success / (long long)s + (success % s > 0);
		int idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
		result.emplace_back(size - idx);
	}

	return result;
}
