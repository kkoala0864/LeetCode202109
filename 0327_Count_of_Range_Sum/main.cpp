#include <Solution.h>

int main(void) {
	vector<int> input = {2147483647,-2147483648,-1,0};
	int low = -1;
	int upper = 0;
	Solution *test = new Solution();
	cout << test->countRangeSum(input, low, upper) << endl;
	return 0;
}
