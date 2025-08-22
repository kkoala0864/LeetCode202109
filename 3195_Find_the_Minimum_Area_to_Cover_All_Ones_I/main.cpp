#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,1,0},{1,0,1}};
	Solution *test = new Solution();
	cout << test->minimumArea(input) << endl;
	return 0;
}
