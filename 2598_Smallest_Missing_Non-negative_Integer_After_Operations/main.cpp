#include <Solution.h>

int main(void) {
  vector<int> input = {3,0,3,2,4,2,1,1,0,4};
  int value = 5;
  Solution *test = new Solution();
  cout << test->findSmallestInteger(input, value) << endl;
  return 0;
}
