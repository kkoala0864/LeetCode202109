#include <Solution.h>

string getHash(const vector<int>& nums) {
	string result;
	for (int i = 0 ; i < nums.size() - 1 ; ++i) {
		result += to_string(nums[i]);
		result += "|";
	}
	result += to_string(nums.back());
	return result;
}

vector<vector<int>> getVec(const vector<int>& nums, int l, int r) {
	vector<vector<int>> result;
	vector<int> rest, insert;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (l <= i && i <= r) {
			insert.emplace_back(nums[i]);
		} else {
			rest.emplace_back(nums[i]);
		}
	}

	vector<int> lp;
	for (int i = 0 ; i <= rest.size() ; ++i) {
		vector<int> cur = lp;
		for (const auto& v : insert) cur.emplace_back(v);
		for (int j = i ; j < rest.size() ; ++j) {
			cur.emplace_back(rest[j]);
		}
		result.emplace_back(cur);
		if (i < rest.size()) lp.emplace_back(rest[i]);
	}
	return result;
}

int Solution::minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
	queue<vector<int>> que, next;

	que.emplace(nums1);
	unordered_set<string> visited;
	visited.emplace(getHash(nums1));
	int size = nums1.size();
	int result = 0;

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		int i = 0;
		for (; i < size ; ++i) {
			if (cur[i] != nums2[i]) break;
		}
		if (i == size) return result;
		for (int i = 1 ; i <= size - 1 ; ++i) {
			for (int l = 0 ; l <= (size - i) ; ++l) {
				int r = l + i - 1;
				auto candidate = getVec(cur, l, r);
				for (const auto& n : candidate) {
					string h = getHash(n);
					if (visited.count(h)) continue;
					visited.emplace(h);
					next.emplace(n);
				}
			}
		}
		if (que.empty()) {
			que = std::move(next);
			++result;
		}
	}
	return -1;
}
