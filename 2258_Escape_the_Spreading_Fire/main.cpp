#include <Solution.h>

int main(void) {
	vector<vector<int>> grid = {{0,0,0,0,0},{0,2,0,2,0},{0,2,0,2,0},{0,2,1,2,0},{0,2,2,2,0},{0,0,0,0,0}};
	Solution *test = new Solution();
	cout << test->maximumMinutes(grid) << endl;
	return 0;
}
