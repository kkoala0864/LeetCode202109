#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4};
	Solution *test = new Solution();
	cout << test->minimumOperations(input) << endl;
	return 0;
}
