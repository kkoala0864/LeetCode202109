#include <Solution.h>

int getCnt(vector<int>& m) {
	int n = m.size();
	stack<int> st;
	vector<int> dp(n, 0);
	int cnt = 0;
	for (int i = 0 ; i < n ; ++i) {
		while (!st.empty() && m[st.top()] >= m[i]) {
			st.pop();
		}
		if (st.empty()) {
			dp[i] = m[i] * (i + 1);
		} else {
			dp[i] = dp[st.top()] + m[i] * (i - st.top());
		}
		cnt += dp[i];
		st.emplace(i);
	}
	return cnt;
}

int Solution::numSubmat(vector<vector<int>>& mat) {
	int m = mat.size();
	int n = mat[0].size();
	for (int i = 1 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (mat[i][j] == 0) continue;
			mat[i][j] = mat[i-1][j] + 1;
		}
	}

	int result = 0;
	for (int i = 0 ; i < m ; ++i) {
		result += getCnt(mat[i]);
	}
	return result;
}
