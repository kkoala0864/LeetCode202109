#include <Solution.h>
#include <vector>
#include <algorithm>
#include <iostream>

//                                          mr
// X X {X X X X X X X X X X X X X X X X X X X} X X X X
//            j          ctr          i

int getP(const string& s) {
	string t(1, '#');
	for (const auto& c : s) {
		t.push_back(c);
		t.push_back('#');
	}

	int size = t.size();

	vector<int> p(size, 0);
	int ctr = -1;
	int mr = -1;

	for (int i = 0 ; i < size ; ++i) {
		if (i <= mr) {
			int j = (2 * ctr) - i;
			p[i] = min(p[j], mr - i + 1);
		}

		while ((i + p[i]) < size && (i - p[i]) >= 0 && t[i+p[i]] == t[i-p[i]]) {
			++p[i];
		}
		--p[i];

		if (i + p[i] > mr) {
			ctr = i;
			mr = i + p[i];
		}
	}
	int maxLen = 0;

	for (int i = 0 ; i < size ; ++i) {
		if (p[i] != i) continue;
		maxLen = max(maxLen, p[i]);
	}
	return maxLen;
}

string Solution::manacher(string s) {
	int maxPalinSize = getP(s);

	string tail = s.substr(maxPalinSize);
	reverse(tail.begin(), tail.end());
	return tail + s;
}
