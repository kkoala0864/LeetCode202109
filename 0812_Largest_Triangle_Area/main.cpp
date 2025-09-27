#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,0},{0,1},{1,0},{0,2},{2,0}};
	Solution *test = new Solution();
	cout << test->largestTriangleArea(input) << endl;
	return 0;
}
