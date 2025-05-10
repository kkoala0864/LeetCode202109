#include <Solution.h>

int main(void) {
	vector<vector<int>> input ={{6,1},{3,2},{2,3}};
	int target = 6;
	Solution *test = new Solution();
	cout << test->waysToReachTarget(target, input) << endl;
	return 0;
}
