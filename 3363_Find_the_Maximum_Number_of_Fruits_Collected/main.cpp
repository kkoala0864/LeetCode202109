#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,1}, {1,1}};
	Solution *test = new Solution();
	cout << test->maxCollectedFruits(input) << endl;
	return 0;
}
