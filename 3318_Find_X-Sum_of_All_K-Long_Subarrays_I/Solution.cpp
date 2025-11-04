#include <Solution.h>

void add(int v, map<int, set<int, greater<>>, greater<>>& m, unordered_map<int, int>& cnt) {
	int oCnt = cnt[v];
	++cnt[v];
	if (oCnt > 0) {
		m[oCnt].erase(v);
	}
	m[cnt[v]].emplace(v);
}

void sub(int v, map<int, set<int, greater<>>, greater<>>& m, unordered_map<int, int>& cnt) {
	int oCnt = cnt[v];
	--cnt[v];
	m[oCnt].erase(v);
	if (cnt[v] > 0) m[cnt[v]].emplace(v);
}

int getCnt(int x, map<int, set<int, greater<>>, greater<>>& m) {
	int result = 0;
	for (const auto& e : m) {
		for (const auto& v : e.second) {
			if (x == 0) break;
			result += (v * e.first);
			--x;
		}
		if (x == 0) break;
	}
	return result;
}

vector<int> Solution::findXSum(vector<int>& nums, int k, int x) {
	vector<int> result;
	map<int, set<int, greater<>>, greater<>> m;
	unordered_map<int, int> cnt;

	for (int i = 0 ; i < nums.size() ; ++i) {
		add(nums[i], m, cnt);
		if (i >= k) {
			sub(nums[i-k], m, cnt);
		}
		if (i >= k - 1) {
			result.emplace_back(getCnt(x, m));
		}
	}

	return result;
}
