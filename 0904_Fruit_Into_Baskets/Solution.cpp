#include <Solution.h>

int Solution::totalFruit(vector<int> &fruits) {
	int l = 0;
	int result = 0;
	unordered_map<int, int> cnt;
	for (int r = 0 ; r < fruits.size() ; ++r) {
		++cnt[fruits[r]];

		while (l < r && cnt.size() > 2) {
			--cnt[fruits[l]];
			if (cnt[fruits[l]] == 0) cnt.erase(fruits[l]);
			++l;
		}
		result = max(result, r - l + 1);
	}
	return result;
}
