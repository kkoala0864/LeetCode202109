#include <Solution.h>

int Solution::findSmallestInteger(vector<int>& nums, int value) {
  vector<int> cnt(value, 0);
  for (const auto& v : nums) {
    int tmp = ((v % value) + value) % value;
    ++cnt[tmp];
  }

  for (int i = 0 ; i < nums.size() ; ++i) {
    if (cnt[i % value] == 0) return i;
    --cnt[i % value];
  }
  return nums.size();

}
