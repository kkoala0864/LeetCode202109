#include <Solution.h>

int main(void) {
	vector<vector<int>> ghosts = {{1,8},{-9,0},{-7,-6},{4,3},{1,3}};
	vector<int> target = {6,-9};
	Solution *test = new Solution();
	cout << test->escapeGhosts(ghosts, target) << endl;
	return 0;
}
