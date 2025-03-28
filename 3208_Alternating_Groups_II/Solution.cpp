#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::numberOfAlternatingGroups(vector<int> &colors, int k) {
	int size = colors.size();
	int result = 0;
	int l = 0;
	for (int i = 1; i < (size + k - 1); ++i) {
		if (colors[i % size] == colors[(i - 1 + size) % size]) {
			l = i;
			continue;
		}
		int cur = i;
		if (cur < l)
			cur += size;
		if ((cur - l + 1) >= k) {
			++result;
		}
	}
	return result;
}
