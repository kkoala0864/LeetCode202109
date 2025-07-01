#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,1,1,1,0},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,0,1}};
	Solution *test = new Solution();
	cout << test->countPyramids(input) << endl;
	return 0;
}
