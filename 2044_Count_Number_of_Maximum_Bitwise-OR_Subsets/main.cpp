#include <Solution.h>

int main(void) {
	vector<int> input = {2,2,2};
	Solution *test = new Solution();
	cout << test->countMaxOrSubsets(input) << endl;
	return 0;
}
