#include <Solution.h>

int main(void) {
	vector<int> input = {1,3,2};
	int k = 2;
	Solution *test = new Solution();
	cout << test->maxTotalValue(input, k) << endl;
	return 0;
}
