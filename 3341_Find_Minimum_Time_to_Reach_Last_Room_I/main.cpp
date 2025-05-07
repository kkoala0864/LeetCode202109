#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,4},{4,4}};
	Solution *test = new Solution();
	cout << test->minTimeToReach(input) << endl;
	return 0;
}
