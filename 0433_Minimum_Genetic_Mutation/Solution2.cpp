#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>

using std::queue;
using std::unordered_set;

int Solution::minMutation2(string start, string end, vector<string> &bank) {
	unordered_set<string> gb;

	for (const auto &b : bank)
		gb.emplace(b);
	if (gb.count(end) == 0)
		return -1;

	queue<string> que, next;
	string gene("ACGT");
	int result = 0;

	que.emplace(start);
	while (!que.empty()) {
		string cur = que.front();
		que.pop();

		if (cur == end)
			return result;

		for (int i = 0; i < cur.size(); ++i) {
			string tmp = cur;
			for (int gi = 0; gi < gene.size(); ++gi) {
				tmp[i] = gene[gi];
				if (gb.count(tmp) == 0)
					continue;
				gb.erase(tmp);
				next.emplace(tmp);
			}
		}
		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}
