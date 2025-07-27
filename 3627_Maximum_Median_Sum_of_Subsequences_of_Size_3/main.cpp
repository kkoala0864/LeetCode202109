#include <Solution.h>

int main(void) {
	vector<int> input = {2,1,3,2,1,3};
	Solution *test = new Solution();
	cout << test->maximumMedianSum(input) << endl;
	return 0;
}
