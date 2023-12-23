#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;
using std::pair;

bool Solution::isPathCrossing(string path) {
	vector<vector<bool>> m(2001, vector<bool>(2001, false));
	pair<int, int> cur(1000, 1000);

	m[cur.first][cur.second] = true;

	for (const auto& c : path) {
		switch (c) {
			case 'N' :
				++cur.first;
				break;
			case 'S' :
				--cur.first;
				break;
			case 'E' :
				++cur.second;
				break;
			case 'W' :
				--cur.second;
				break;
			default:
				break;
		}
		if (m[cur.first][cur.second]) return true;
		m[cur.first][cur.second] = true;
	}
	return false;
}

