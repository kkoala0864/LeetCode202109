#include <Solution.h>
#include <iostream>

vector<int> Solution::missingRolls(vector<int> &rolls, int mean, int n) {
	int sum = 0;
	vector<int> result;
	int total = mean * (n + rolls.size());

	for (const auto &r : rolls) {
		total -= r;
		if (total < n)
			return result;
	}
	if (total > (n * 6))
		return result;

	int aver = total / n;
	int rest = total % n;

	for (int i = 0; i < n; ++i) {
		if (i < rest) {
			result.emplace_back(aver + 1);
		} else {
			result.emplace_back(aver);
		}
	}
	return result;
}
