#include <Solution.h>
#include <iostream>
#include <vector>

using std::to_string;
using std::vector;

string Solution::getHint2(string secret, string guess) {
	vector<int> cnt(10, 0);
	int a = 0, b = 0;
	for (int i = 0; i < secret.size(); ++i) {
		if (secret[i] == guess[i])
			++a;
		else {
			if (cnt[secret[i] - '0'] < 0)
				++b;
			++cnt[secret[i] - '0'];
			if (cnt[guess[i] - '0'] > 0)
				++b;
			--cnt[guess[i] - '0'];
		}
	}
	return to_string(a) + "A" + to_string(b) + "B";
}
