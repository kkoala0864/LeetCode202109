#include <Solution.h>

vector<int> getMin(const vector<int>& lhs, const vector<int>& rhs) {
  int ls = lhs.size();
  int rs = rhs.size();

  for (int i = 0 ; i < min(ls, rs) ; ++i) {
    if (lhs[i] == rhs[i]) continue;
    return lhs[i] < rhs[i] ? lhs : rhs;
  }
  return ls < rs ? rhs : rhs;
}

vector<int> Solution::cheapestJump(vector<int>& coins, int maxJump) {
    int size = coins.size();
    vector<pair<int, vector<int>>> dp(size);

    dp[0] = pair<int, vector<int>>(coins[0], vector<int>(1, 1));

    for (int i = 1 ; i < size ; ++i) {
        dp[i].first = INT_MAX / 2;
        if (coins[i] == -1) continue;
        for (int j = max(0, i - maxJump) ; j < i ; ++j) {
              if (coins[j] == -1) continue;
              int cur = dp[j].first + coins[i];
              if (cur < dp[i].first) {
                  dp[i].first = cur;
                  dp[i].second = dp[j].second;
              } else if (cur == dp[i].first) {
                  dp[i].second = getMin(dp[i].second, dp[j].second);
              }
        }
        if (dp[i].first != (INT_MAX / 2)) dp[i].second.emplace_back(i + 1);
    }
    return dp.back().second;
}
