#include <Solution.h>

void dfs(int i, vector<bool>& visited, vector<int>& nums, unordered_map<int, int>& oriOrder, int& cnt) {
	if (visited[i]) return;
	++cnt;
	visited[i] = true;
	dfs(oriOrder[nums[i]], visited, nums, oriOrder, cnt);
}

int Solution::minSwaps(vector<int>& nums) {

	auto cmp = [](const int& lhs, const int& rhs) {
		int ls = 0;
		int rs = 0;
		int tmp = lhs;
		while (tmp > 0) {
			ls += (tmp % 10);
			tmp /= 10;
		}
		tmp = rhs;
		while (tmp > 0) {
			rs += (tmp % 10);
			tmp /= 10;
		}
		return ls == rs ? lhs < rhs : ls < rs;
	};

	unordered_map<int, int> oriOrder;
	for (int i = 0 ; i < nums.size() ; ++i) {
		oriOrder[nums[i]] = i;
	}

	vector<bool> visited(nums.size(), false);
	sort(nums.begin(), nums.end(), cmp);
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (visited[i] || i == oriOrder[nums[i]]) continue;
		int cnt = 0;
		dfs(i, visited, nums, oriOrder, cnt);
		result += cnt-1;
	}
	return result;
}
