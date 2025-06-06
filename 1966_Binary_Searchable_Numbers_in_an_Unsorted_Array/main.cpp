#include <Solution.h>

int main(void) {
	vector<int> input = {-1,5,2};
	Solution *test = new Solution();
	cout << test->binarySearchableNumbers(input) << endl;
	return 0;
}
