#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::min;

string find(unordered_map<string, string>& m, const string& idx) {
	if (m[idx] == idx) return idx;
	return m[idx] = find(m, m[idx]);
}

string Solution::destCity(vector<vector<string>>& paths) {
	unordered_map<string, string> m;

	for (const auto& p : paths) {
		if (m.count(p[0]) == 0) m[p[0]] = p[0];
		if (m.count(p[1]) == 0) m[p[1]] = p[1];
		string lr = find(m, p[0]);
		string rr = find(m, p[1]);
		if (lr == rr) continue;
		m[lr] = m[rr];
	}
	return find(m, m.begin()->first);
}
