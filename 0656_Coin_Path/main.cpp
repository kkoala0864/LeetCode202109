#include <Solution.h>

int main(void) {
  vector<int> input = {1,2,4,-1,2};
  int maxJump = 1;
  Solution *test = new Solution();
  auto result = test->cheapestJump(input, maxJump);
  for (const auto& v : result) cout << v << " ";
  cout << endl;
  return 0;
}
