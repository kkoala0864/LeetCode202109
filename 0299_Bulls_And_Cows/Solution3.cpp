#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::to_string;
using std::min;

string Solution::getHint3(string secret, string guess) {
	int aCnt = 0;
	int bCnt = 0;
	vector<int> sCnt(10, 0);
	vector<int> gCnt(10, 0);

	for (int i = 0 ; i < secret.size() ; ++i) {
		if (secret[i] == guess[i]) ++aCnt;
		else {
			++sCnt[secret[i]-'0'];
			++gCnt[guess[i]-'0'];
		}
	}

	for (int i = 0 ; i < 10 ; ++i) {
		bCnt += min(sCnt[i], gCnt[i]);
	}
	return to_string(aCnt) + "A" + to_string(bCnt) + "B";
}
