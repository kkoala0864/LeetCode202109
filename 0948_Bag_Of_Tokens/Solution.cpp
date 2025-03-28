#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::bagOfTokensScore(vector<int> &tokens, int power) {
	sort(tokens.begin(), tokens.end());

	int curPower = power;
	int curScore = 0;
	int getScoreIdx = 0, getPowerIdx = tokens.size() - 1;
	while (getScoreIdx <= getPowerIdx) {
		while (getScoreIdx <= getPowerIdx && curPower >= tokens[getScoreIdx]) {
			++curScore;
			curPower -= tokens[getScoreIdx++];
		}
		int oriScore = curScore;
		while (getScoreIdx <= getPowerIdx && curScore > 0 && curPower < tokens[getScoreIdx]) {
			--curScore;
			curPower += tokens[getPowerIdx--];
		}
		if (getScoreIdx > getPowerIdx || curPower < tokens[getScoreIdx])
			return oriScore;
	}
	return curScore;
}
