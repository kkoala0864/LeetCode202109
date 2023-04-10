#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<int> Solution::successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
	sort(potions.begin(), potions.end());

	vector<int> result;
	for (int i = 0 ; i < spells.size() ; ++i) {
		long long val = success / spells[i];
		if (success % spells[i]) ++val;

		int idx = lower_bound(potions.begin(), potions.end(), val) - potions.begin();
		result.emplace_back(potions.size() - idx);
	}
	return result;
}
