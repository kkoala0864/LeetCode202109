#include <Solution.h>
#include <algorithm>
#include <map>

// 0 1 2 3 4 5
bool check(vector<int>& t, vector<int>& w, int k, int pills, int strength) {
	map<int, int> wm;
	for (const auto& v : w) {
		++wm[v];
	}

	for (int i = k - 1 ; i >= 0 ; --i) {
		auto iter = wm.rbegin();
		if (iter->first >= t[i]) {
			--iter->second;
			if (iter->second == 0) {
				wm.erase(iter->first);
			}
		} else {
			if (pills == 0) return false;
			auto piter = wm.lower_bound(t[i] - strength);
			if (piter == wm.end()) return false;
			--pills;
			--piter->second;
			if (piter->second == 0) {
				wm.erase(piter->first);
			}
		}
	}
	return true;
}

int Solution::maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
	int result = 0;

	sort(tasks.begin(), tasks.end());
	sort(workers.begin(), workers.end());

	int l = 0, r = min(workers.size(), tasks.size());
	int mid = 0;

	while (l < r) {
		mid = r - ((r - l) >> 1);

		bool ret = check(tasks, workers, mid, pills, strength);
		if (ret) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}
