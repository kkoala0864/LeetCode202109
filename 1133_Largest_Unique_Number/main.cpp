#include <Solution.h>

int main(void) {
	vector<int> input = {5, 7, 3, 9, 4, 9, 8, 3, 1};
	Solution *test = new Solution();
	cout << test->largestUniqueNumber(input) << endl;
	return 0;
}
