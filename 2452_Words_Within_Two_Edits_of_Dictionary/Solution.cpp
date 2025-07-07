#include <Solution.h>

vector<string> Solution::twoEditWords(vector<string>& queries, vector<string>& dictionary) {
	vector<string> result;
	for (const auto& q : queries) {
		for (const auto& d : dictionary) {
			int diff = 0;
			for (int i = 0 ; i < q.size() ; ++i) {
				if (q[i] == d[i]) continue;
				++diff;
			}
			if (diff <= 2) {
				result.emplace_back(q);
				break;
			}
		}
	}
	return result;
}
