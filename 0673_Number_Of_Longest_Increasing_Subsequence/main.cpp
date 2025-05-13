#include <Solution.h>

int main(void) {
	vector<int> input = {1,3,5,4,7};
	Solution *test = new Solution();
	cout << test->findNumberOfLIS(input) << endl;
	return 0;
}
