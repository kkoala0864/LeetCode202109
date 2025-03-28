#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::min;
using std::unordered_set;

int find(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find(root, root[idx]);
}

bool isSim(const string &s1, const string &s2) {
	int cnt = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i])
			++cnt;
	}
	return cnt < 3;
}

int Solution::numSimilarGroups(vector<string> &strs) {
	vector<int> root;
	for (int i = 0; i < strs.size(); ++i) {
		root.emplace_back(i);
		for (int j = 0; j < i; ++j) {
			if (!isSim(strs[i], strs[j]))
				continue;
			int lr = find(root, i);
			int rr = find(root, j);
			if (lr == rr)
				continue;
			root[lr] = root[rr] = min(lr, rr);
		}
	}
	unordered_set<int> us;
	for (int i = 0; i < strs.size(); ++i) {
		us.emplace(find(root, i));
	}
	return us.size();
}
