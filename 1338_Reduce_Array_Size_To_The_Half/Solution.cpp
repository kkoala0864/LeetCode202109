#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::min;

int Solution::minSetSize(vector<int>& arr) {
	int target = arr.size() / 2;
	unordered_map<int, int> cnt;
	for (const auto& v : arr) ++cnt[v];

	vector<int> list;
	for (const auto& c : cnt) list.emplace_back(c.second);
	sort(list.begin(), list.end());

	int l = list.size() - 2, r = list.size() - 1;
	int sum = list.back();
	int result = sum >= target ? 1 : arr.size();
	while (l >= 0) {
		sum += list[l];
		while (r > l && sum >= target) {
			result = min(result, r - l + 1);
			sum -= list[r];
			--r;
		}
		--l;
	}
	return result;
}
