#include <Solution.h>

string Solution::strWithout3a3b(int a, int b) {
	int big = max(a, b);
	int small = min(a, b);

	char bc = big == a ? 'a' : 'b';
	char sc = bc == 'a' ? 'b' : 'a';

	string result;
	while (big > 0) {
		int cnt = min(big, 2);
		big -= cnt;
		result += string(cnt, bc);
		if (small > 0) {
			result += string(1, sc);
			--small;
		}
	}
	if (small > 0) {
		string tmp;
		for (const auto& c : result) {
			tmp.push_back(c);
			if (c == sc && small > 0) {
				tmp.push_back(sc);
				--small;
			}
		}
		result = std::move(tmp);
	}
	return result;
}

