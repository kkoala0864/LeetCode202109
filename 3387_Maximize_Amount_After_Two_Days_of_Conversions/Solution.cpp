#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::pair;
using std::queue;
using std::unordered_map;

double Solution::maxAmount(string initialCurrency, vector<vector<string>> &pairs1, vector<double> &rates1, vector<vector<string>> &pairs2, vector<double> &rates2) {

	vector<unordered_map<string, unordered_map<string, double>>> g(2);
	;

	for (int i = 0; i < pairs1.size(); ++i) {
		g[0][pairs1[i][0]][pairs1[i][1]] = rates1[i];
		g[0][pairs1[i][1]][pairs1[i][0]] = 1 / rates1[i];
	}
	for (int i = 0; i < pairs2.size(); ++i) {
		g[1][pairs2[i][0]][pairs2[i][1]] = rates2[i];
		g[1][pairs2[i][1]][pairs2[i][0]] = 1 / rates2[i];
	}

	unordered_map<string, vector<double>> maxVal;
	queue<pair<string, pair<double, int>>> que;

	maxVal[initialCurrency] = vector<double>(2, 0.0);
	maxVal[initialCurrency][0] = 1.0;
	maxVal[initialCurrency][1] = 1.0;
	que.emplace(pair<string, pair<double, int>>(initialCurrency, pair<double, int>(1.0, 0)));
	que.emplace(pair<string, pair<double, int>>(initialCurrency, pair<double, int>(1.0, 1)));

	while (!que.empty()) {
		string cur = que.front().first;
		double v = que.front().second.first;
		int gi = que.front().second.second;
		que.pop();

		for (int i = 0; i < 2; ++i) {
			if (i >= gi) {
				for (const auto &e : g[i][cur]) {
					double nv = (e.second * v);
					if (maxVal.count(e.first) == 0 || maxVal[e.first][i] < nv) {
						if (maxVal.count(e.first) == 0)
							maxVal[e.first] = vector<double>(2, 0.0);
						maxVal[e.first][i] = nv;
						que.emplace(pair<string, pair<double, int>>(e.first, pair<double, int>(nv, i)));
					}
				}
			}
		}
	}
	return max(maxVal[initialCurrency][0], maxVal[initialCurrency][1]);
}
