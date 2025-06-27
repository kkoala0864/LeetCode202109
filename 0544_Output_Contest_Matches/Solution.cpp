#include <Solution.h>

string Solution::findContestMatch(int n) {
	vector<string> pair;
	for (int i = 1 ; i <= n ; ++i) {
		pair.emplace_back(to_string(i));
	}

	vector<string> next;
	while (pair.size() > 1) {
		int size = pair.size();
		for (int i = 0 ; i < size / 2 ; ++i) {
			next.emplace_back("(" + pair[i] + "," + pair[size-1-i] + ")");
		}
		pair = move(next);
	}
	return pair[0];
}
