#include <Solution.h>
#include <iostream>

using std::swap;
void reverse(vector<int> &nums, int start, int end) {
	while (start < end) {
		swap(nums[start++], nums[end--]);
	}
}
vector<int> Solution::findPermutation(string s) {
	vector<int> result(1, 1);
	int reverseCnt = 0;

	for (int i = 0; i < s.size(); ++i) {
		result.emplace_back(i + 2);
		if (s[i] == 'I') {
			if (reverseCnt > 0) {
				reverse(result, i - reverseCnt, i);
				reverseCnt = 0;
			}
		} else
			++reverseCnt;
	}
	if (reverseCnt > 0)
		reverse(result, s.size() - reverseCnt, s.size());
	return result;
}
