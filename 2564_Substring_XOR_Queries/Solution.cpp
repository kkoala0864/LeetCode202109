#include <Solution.h>
string getBinStr(int v) {
	string s;
	while (v > 0) {
		s.push_back((v & 1) + '0');
		v = v >> 1;
	}
	return s.empty() ? "0" : s;
}

vector<vector<int>> Solution::substringXorQueries(string s, vector<vector<int>>& queries) {
	vector<int> targets;
	unordered_map<int, vector<int>> szToTargetIdx;
	for (const auto& q : queries) {
		targets.emplace_back(q[0] ^ q[1]);
		string ts = getBinStr(targets.back());
		szToTargetIdx[ts.size()].emplace_back(targets.size() - 1);
	}

	vector<vector<int>> result(targets.size(), vector<int>({-1, -1}));
	int size = s.size();
	for (const auto& e : szToTargetIdx) {
		int sz = e.first;
		unordered_map<int, int> valToIdx;
		int cur = 0;
		cout << sz << endl;
		for (int i = 0 ; i < size ; ++i) {
			cur = cur << 1;
			cur += (s[i] - '0');
			if (i >= sz && (cur & (1 << sz))) {
				cur -= (1 << sz);
			}
			if (i >= (sz - 1)) {
				if (valToIdx.count(cur) == 0) valToIdx[cur] = INT_MAX;
				valToIdx[cur] = min(valToIdx[cur], i - sz + 1);
			}
		}
		for (const auto& ti : e.second) {
			int v = targets[ti];
			if (valToIdx.count(v)) {
				result[ti][0] = valToIdx[v];
				result[ti][1] = valToIdx[v] + sz - 1;
			}
		}
	}
	return result;
}



