#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::unordered_map;
using std::max;

int Solution::totalFruit(vector<int>& fruits) {
	unordered_map<int, int> m;
	int l = 0;
	int result = 0;
	for (int i = 0 ; i < fruits.size() ; ++i) {
		++m[fruits[i]];
		while (m.size() > 2) {
			--m[fruits[l]];
			if (m[fruits[l]] == 0) m.erase(fruits[l]);
			++l;
		}
		if (m.size() <= 2) {
			result = max(result, i - l + 1);
		}
	}
	return result;
}
