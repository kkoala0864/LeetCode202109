#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

int Solution::findLengthOfShortestSubarray(vector<int> &arr) {
	vector<int> pre, post;
	for (int i = 0; i < arr.size(); ++i) {
		if (!pre.empty() && arr[i] < pre.back())
			break;
		pre.emplace_back(arr[i]);
	}
	for (int i = arr.size() - 1; i >= 0; --i) {
		if (!post.empty() && arr[i] > post.back())
			break;
		post.emplace_back(arr[i]);
	}
	reverse(post.begin(), post.end());
	if (pre.size() + post.size() > arr.size())
		return 0;
	int maxLen = max(pre.size(), post.size());
	while (!pre.empty()) {
		int idx = lower_bound(post.begin(), post.end(), pre.back()) - post.begin();
		if (idx != post.size()) {
			maxLen = max(maxLen, (int)pre.size() + (int)post.size() - idx);
		}
		pre.pop_back();
	}
	return arr.size() - maxLen;
}
