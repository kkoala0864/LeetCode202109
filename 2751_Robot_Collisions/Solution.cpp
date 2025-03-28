#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::sort;

vector<int> Solution::survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
	vector<pair<int, int>> robots;
	for (int i = 0; i < positions.size(); ++i)
		robots.emplace_back(pair<int, int>(positions[i], i));
	sort(robots.begin(), robots.end());
	vector<pair<int, int>> st;

	for (auto &r : robots) {
		int curIdx = r.second;
		if (directions[curIdx] == 'R') {
			st.emplace_back(r);
		} else {
			while (!st.empty() && directions[st.back().second] == 'R') {
				int lastIdx = st.back().second;
				if (healths[lastIdx] > healths[curIdx]) {
					--healths[lastIdx];
					healths[curIdx] = 0;
					break;
				} else if (healths[lastIdx] == healths[curIdx]) {
					st.pop_back();
					healths[lastIdx] = 0;
					healths[curIdx] = 0;
					break;
				} else {
					st.pop_back();
					healths[lastIdx] = 0;
					--healths[curIdx];
				}
			}
			if (healths[curIdx] > 0) {
				st.emplace_back(r);
			}
		}
	}
	vector<int> result;
	for (const auto &h : healths)
		if (h > 0)
			result.emplace_back(h);
	return result;
}
