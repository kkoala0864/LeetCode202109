#include <Solution.h>

int main(void) {
	vector<vector<int>> grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
	Solution *test = new Solution();
	cout << test->maxIncreaseKeepingSkyline(grid) << endl;
	return 0;
}
