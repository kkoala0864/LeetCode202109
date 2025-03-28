#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::sort;

vector<int> Solution::frequencySort(vector<int> &nums) {
	vector<int> freqCnt(201, 0);
	for (const auto &v : nums)
		++freqCnt[v + 100];

	vector<pair<int, int>> freqToV;
	for (int i = 0; i < freqCnt.size(); ++i) {
		freqToV.emplace_back(pair<int, int>(freqCnt[i], i - 100));
	}
	auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
		return lhs.first == rhs.first ? lhs.second > rhs.second : lhs.first < rhs.first;
	};
	sort(freqToV.begin(), freqToV.end(), cmp);
	vector<int> result;
	for (auto &f : freqToV) {
		while (f.first-- > 0)
			result.emplace_back(f.second);
	}
	return result;
}
