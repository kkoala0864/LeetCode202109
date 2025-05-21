#include <Solution.h>

bool isPalin(int l, int r, vector<int>& p) {
	int ctr = l + r + 1;
	int rr = 2 * r + 1;
	return (ctr + p[ctr]) >= rr;
}

vector<int> Solution::Manacher(const string &s) {
	string tmp = "#";
	for (const auto& c : s) {
		tmp.push_back(c);
		tmp.push_back('#');
	}

	vector<int> p(tmp.size(), 0);
	int mr = -1;
	int ctr = -1;
	for (int i = 0 ; i < tmp.size() ; ++i) {
		if (i < mr) {
			int j = 2 * ctr - i;
			p[i] = min(p[j], mr - i);
		}

		while (i + p[i] < tmp.size() && i - p[i] >= 0 && tmp[i + p[i]] == tmp[i - p[i]]) {
			++p[i];
		}
		--p[i];

		if (i + p[i] > mr) {
			mr = i + p[i];
			ctr = i;
		}
	}
	return p;
}
