#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool dfs(vector<int> &matchsticks, int &flag, unordered_map<int, bool> &uMap, int sum, int targetSum, int cnt) {
	if (targetSum == sum) {
		++cnt;
		if (cnt == 4)
			return true;
		return dfs(matchsticks, flag, uMap, 0, targetSum, cnt);
	}

	if (uMap.find(sum ^ flag) != uMap.end())
		return uMap[sum ^ flag];

	for (int i = 0; i < matchsticks.size(); ++i) {
		if ((flag >> i) & 1)
			continue;
		if (matchsticks[i] > (targetSum - sum))
			continue;

		int mask = 1 << i;
		flag |= mask;
		if (dfs(matchsticks, flag, uMap, sum + matchsticks[i], targetSum, cnt)) {
			uMap[(sum + matchsticks[i]) ^ flag] = true;
			return true;
		}
		uMap[(sum + matchsticks[i]) ^ flag] = false;
		flag &= ~mask;
	}
	return false;
}

bool Solution::makesquare(vector<int> &matchsticks) {
	int sum = 0;
	for (const auto &m : matchsticks)
		sum += m;
	if (sum % 4)
		return false;
	int targetSum = sum / 4;

	int flag = 0;
	unordered_map<int, bool> uMap;
	return dfs(matchsticks, flag, uMap, 0, targetSum, 0);
}
