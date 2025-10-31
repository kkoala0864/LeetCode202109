#include <Solution.h>

int main(void) {
	vector<int> input = {3,4,2,5,6};
	Solution *test = new Solution();
	cout << test->minNumberOperations(input) << endl;
	return 0;
}
