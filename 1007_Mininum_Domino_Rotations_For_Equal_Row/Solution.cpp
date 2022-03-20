#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::min;
using std::max;

int check(int val, vector<int>& a, vector<int>& b) {
	int result = 0;
	int ra = 0;
	int rb = 0;
	for (int i = 0 ; i < a.size() ; ++i) {
		if (a[i] != val && b[i] != val) return -1;
		else if (a[i] != val) ++ra;
		else if (b[i] != val) ++rb;
	}
	return min(ra, rb);
}

int Solution::minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
	int size = tops.size();
	int r = check(tops[0], tops, bottoms);
	if (r != -1 || tops[0] == bottoms[0]) return r;
	else return check(bottoms[0], tops, bottoms);
}

