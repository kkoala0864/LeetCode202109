#include <Solution.h>

bool dfs(vector<int>& ws, vector<int>& rs, vector<bool>& visited, vector<bool>& cl, int idx, int offset) {
	if (idx == ws.size()) {
		return offset == 0;
	}

	for (int i = cl[idx] ? 0 : 1 ; i < 10 ; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		int cur = (ws[idx] * i) - (rs[idx] * i);
		if (dfs(ws, rs, visited, cl, idx + 1, offset + cur)) return true;
		visited[i] = false;
	}
	return false;
}

bool Solution::isSolvable(vector<string>& words, string result) {
	unordered_map<char, int> cToi;
	vector<bool> visited(10, false);
	int mi = 0;

	for (const auto& w : words) {
		for (const auto& c : w) {
			if (cToi.count(c) == 0) cToi[c] = mi++;
		}
	}
	for (const auto& c : result) {
		if (cToi.count(c) == 0) cToi[c] = mi++;
	}

	vector<int> ws(cToi.size(), 0);
	vector<int> rs(cToi.size(), 0);
	vector<bool> canleading(cToi.size(), true);
	for (const auto& w : words) {
		int base = 1;
		for (int i = w.size() - 1 ; i >= 0 ; --i) {
			ws[cToi[w[i]]] += base;
			base *= 10;
			if (i == 0 && w.size() > 1) canleading[cToi[w[i]]] = false;
		}
	}
	int base = 1;
	for (int i = result.size() - 1 ; i >= 0 ; --i) {
		rs[cToi[result[i]]] += base;
		base *= 10;
		if (i == 0 && result.size() > 1) canleading[cToi[result[i]]] = false;
	}

	return dfs(ws, rs, visited, canleading, 0, 0);
}
