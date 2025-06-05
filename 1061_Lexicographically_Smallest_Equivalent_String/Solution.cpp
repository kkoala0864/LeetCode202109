#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

string Solution::smallestEquivalentString(string s1, string s2, string baseStr) {
	vector<int> root;
	for (int i = 0 ; i < 26 ; ++i) {
		root.emplace_back(i);
	}

	for (int i = 0 ; i < s1.size() ; ++i) {
		int lr = find(root, s1[i] - 'a');
		int rr = find(root, s2[i] - 'a');
		if (lr == rr) continue;
		root[lr] = root[rr] = min(lr, rr);
	}

	string result;
	for (int i = 0 ; i < baseStr.size() ; ++i) {
		result.push_back(find(root, baseStr[i] - 'a') + 'a');
	}
	return result;
}
