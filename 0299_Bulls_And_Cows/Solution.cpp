#include <Solution.h>
#include <iostream>
#include <vector>

using std::to_string;
using std::vector;

string Solution::getHint(string secret, string guess) {
	vector<int> loc(10, 0);
	int A = 0;
	int B = 0;
	for (int i = 0; i < secret.size(); ++i) {
		if (secret[i] == guess[i]) {
			guess[i] = '-';
			++A;
		} else
			++loc[secret[i] - '0'];
	}

	for (const auto &iter : guess) {
		if (iter == '-')
			continue;
		if (loc[iter - '0'] == 0)
			continue;
		--loc[iter - '0'];
		++B;
	}
	string result = to_string(A) + "A" + to_string(B) + "B";
	return result;
}
