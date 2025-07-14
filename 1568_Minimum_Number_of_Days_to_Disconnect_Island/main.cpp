#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
	Solution *test = new Solution();
	cout << test->minDays(input) << endl;
	return 0;
}
