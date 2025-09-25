#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	Solution *test = new Solution();
	cout << test->minimumTotal(input) << endl;
	return 0;
}
