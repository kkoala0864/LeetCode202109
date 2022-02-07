#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

char Solution::findTheDifference(string s, string t) {
	vector<int> map(26, 0);
	for (const auto& iter : s) ++map[iter-'a'];

	for (const auto& iter : t) {
		--map[iter-'a'];
		if (map[iter-'a'] < 0) return iter;
	}
	return ' ';
}
