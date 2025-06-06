#include <Solution.h>

long long Solution::numberOfSubarrays(vector<int>& nums) {
	int size = nums.size();
	stack<int> st;
	vector<int> preMax(size, -1);

	for (int i = 0 ; i < size ; ++i) {
		while (!st.empty() && nums[st.top()] <= nums[i]) {
			st.pop();
		}
		if (!st.empty()) {
			preMax[i] = st.top();
		}
		st.emplace(i);
	}

	long long result = 0;
	unordered_map<int, vector<int>> m;
	for (int i = 0 ; i < nums.size() ; ++i) {
		m[nums[i]].emplace_back(i);

		auto iter = lower_bound(m[nums[i]].begin(), m[nums[i]].end(), preMax[i]);
		result += (m[nums[i]].end() - iter);
	}
	return result;

}
