#include <Solution.h>

vector<string> Solution::divideString(string s, int k, char fill) {
	vector<string> result;
	for (int i = 0 ; i < s.size() ; i += k) {
		string cur = s.substr(i, k);
		if (cur.size() < k) {
			cur += string(k - cur.size(), fill);
		}
		result.emplace_back(cur);
	}
	return result;
}
