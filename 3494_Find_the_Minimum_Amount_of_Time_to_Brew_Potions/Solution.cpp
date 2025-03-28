#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

long long dfs(vector<int> &skill, int si, vector<int> &mana, int mi, vector<long long> &endTime, long long lastSkillEnd) {

	if (si == skill.size()) {
		return lastSkillEnd;
	}
	long long v = max(lastSkillEnd, endTime[si]);
	endTime[si] = dfs(skill, si + 1, mana, mi, endTime, v + ((long long)skill[si] * (long long)mana[mi]));
	return endTime[si] - ((long long)skill[si] * (long long)mana[mi]);
}

long long Solution::minTime(vector<int> &skill, vector<int> &mana) {
	int size = skill.size();
	vector<long long> endTime(size, 0);

	for (int i = 0; i < mana.size(); ++i) {
		dfs(skill, 0, mana, i, endTime, 0);
	}
	return endTime.back();
}
