#include <Solution.h>

vector<int> Solution::avoidFlood(vector<int>& rains) {
	unordered_map<int, int> lake;

	int size = rains.size();
	set<int> dryIdx;

	for (int i = 0 ; i < size ; ++i) {
		if (rains[i] == 0) dryIdx.emplace(i);
		else {
			int l = rains[i];
			if (lake.count(l)) {
				if (dryIdx.empty()) return vector<int>();
				else {
					int lastIdx = lake[l];
					auto iter = dryIdx.upper_bound(lastIdx);
					if (iter == dryIdx.end()) return vector<int>();
					rains[*iter] = l;
					rains[lastIdx] = -1;
					dryIdx.erase(*iter);
				}
			}
			lake[l] = i;
		}
	}
	for (const auto& e : lake) rains[e.second] = -1;
	for (const auto& e : dryIdx) rains[e] = 1;
	return rains;

}
