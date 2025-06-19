#include <Solution.h>

vector<vector<int>> Solution::removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved) {
	vector<vector<int>> result;
	sort(intervals.begin(), intervals.end());

	for (const auto& i : intervals) {
		if ((i[0] >= toBeRemoved[1]) || (i[1] < toBeRemoved[0])) {
			result.emplace_back(i);
		} else if (toBeRemoved[0] <= i[0] && i[1] <= toBeRemoved[1]) {
			continue;
		} else if (i[0] < toBeRemoved[0] && toBeRemoved[1] < i[1]) {
			result.emplace_back(vector<int>({i[0], toBeRemoved[0]}));
			result.emplace_back(vector<int>({toBeRemoved[1], i[1]}));
		} else if (i[0] < toBeRemoved[0]) {
			result.emplace_back(vector<int>({i[0], toBeRemoved[0]}));
		} else if (toBeRemoved[1] < i[1]) {
			result.emplace_back(vector<int>({toBeRemoved[1], i[1]}));
		}
	}
	return result;
}
