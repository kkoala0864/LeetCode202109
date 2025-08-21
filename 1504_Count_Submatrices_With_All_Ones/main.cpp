#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
	Solution *test = new Solution();
	cout << test->numSubmat(input) << endl;
	return 0;
}
