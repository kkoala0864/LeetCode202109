#include <Solution.h>
#include <map>

vector<vector<long long>> Solution::splitPainting(vector<vector<int>>& segments) {

	map<long long, long long> line;
	for (const auto& s : segments) {
		line[s[0]] += s[2];
		line[s[1]] -= s[2];
	}
	vector<vector<long long>> result;
	long long cnt = 0;
	long long last = -1;
	for (const auto& e : line) {
		if (last != -1 && cnt != 0) {
			result.emplace_back(vector<long long>({last, e.first, cnt}));
		}
		last = e.first;
		cnt += e.second;
	}
	return result;
}
