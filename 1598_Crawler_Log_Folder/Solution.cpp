#include <Solution.h>
#include <iostream>

int Solution::minOperations(vector<string> &logs) {
	int cnt = 0;
	for (const auto &l : logs) {
		if (l == "./")
			continue;
		else if (l == "../") {
			if (cnt > 0)
				--cnt;
		} else {
			++cnt;
		}
	}
	return cnt;
}
