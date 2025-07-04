#include <Solution.h>

int Solution::largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
	unordered_map<int ,int> labelCnt;

	vector<pair<int, int>> list;
	int size = values.size();
	for (int i = 0 ; i < size ; ++i) {
		list.emplace_back(pair<int, int>(values[i], labels[i]));
	}
	sort(list.begin(), list.end(), greater<>());

	int result = 0;
	int vCnt = 0;
	for (const auto& p : list) {
		if (labelCnt[p.second] >= useLimit) continue;
		++labelCnt[p.second];
		result += p.first;
		++vCnt;
		if (vCnt == numWanted) break;
	}
	return result;

}
