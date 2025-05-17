#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,1,2,1};
	int k = 5;
	Solution *test = new Solution();
	cout << test->minCost(input, k) << endl;
	return 0;
}
