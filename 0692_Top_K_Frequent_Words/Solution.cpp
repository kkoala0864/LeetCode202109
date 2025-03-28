#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::pair;
using std::priority_queue;
using std::unordered_map;

struct cmp
{
	bool operator()(pair<int, string> &lhs, pair<int, string> &rhs) const {
		return lhs.first == rhs.first ? lhs.second > rhs.second : lhs.first < rhs.first;
	}
};

vector<string> Solution::topKFrequent(vector<string> &words, int k) {
	unordered_map<string, int> uMap;

	for (const auto &w : words)
		++uMap[w];

	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
	for (const auto &v : uMap) {
		pq.emplace(pair<int, string>(v.second, v.first));
	}

	vector<string> result;
	while (k--) {
		result.push_back(pq.top().second);
		pq.pop();
	}
	return result;
}
