#include <Solution.h>

int main(void) {
	vector<int> input = {4, 6};
	vector<vector<int>> query = {{0, 0}, {0, 1}, {1, 1}, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {1, 1}, {1, 1}, {1, 1}, {0, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 1}};
	Solution *test = new Solution();
	cout << test->isZeroArray(input, query) << endl;
	return 0;
}
