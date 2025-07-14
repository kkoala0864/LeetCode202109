#include <Solution.h>

int main(void) {
	vector<int> input = {4,2,5,3};
	Solution *test = new Solution();
	cout << test->maxAlternatingSum(input) << endl;
	return 0;
}
