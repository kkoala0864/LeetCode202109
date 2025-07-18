#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

int Solution::minSwapsCouples(vector<int>& row) {
	int size = row.size() / 2;
	vector<int> root;
	for (int i = 0 ; i < size ; ++i) root.emplace_back(i);

	for (int i = 0 ; i < row.size() ; i += 2) {
		int lr = find(root, row[i] / 2);
		int rr = find(root, row[i+1] / 2);
		if (lr == rr) continue;
		root[lr] = root[rr] = min(lr, rr);
	}

	vector<int> cnt(size, 0);
	int result = 0;
	for (int i = 0 ; i < size ; ++i) {
		++cnt[find(root, i)];
	}
	for (const auto& v : cnt) {
		if (v == 0) continue;
		result += (v - 1);
	}
	return result;
}
