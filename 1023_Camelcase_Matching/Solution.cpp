#include <Solution.h>
#include <iostream>

vector<bool> Solution::camelMatch(vector<string>& queries, string pattern) {
	vector<bool> result;

	for (const auto& q : queries) {
		int pi = 0;
		int i = 0;
		for (; i < q.size() ; ++i) {
			if (isupper(q[i])) {
				if (pi >= pattern.size() || islower(pattern[pi])) {
					break;
				} else {
					if (q[i] != pattern[pi]) {
						break;
					} else {
						++pi;
					}
				}
			} else {
				if (pi >= pattern.size() || q[i] != pattern[pi]) {
					continue;
				} else {
					++pi;
				}
			}
		}
		result.push_back(i == q.size() && pi == pattern.size());
	}
	return result;
}
