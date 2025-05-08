#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0, 0, 0, 0}, {0, 0, 0, 0}};
	Solution *test = new Solution();
	cout << test->minTimeToReach(input) << endl;
	return 0;
}
