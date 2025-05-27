#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
	Solution *test = new Solution();
	cout << test->isRectangleCover(input) << endl;
	return 0;
}
