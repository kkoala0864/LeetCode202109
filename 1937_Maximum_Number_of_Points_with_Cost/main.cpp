#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,2,3},{1,5,1},{3,1,1}};
	Solution *test = new Solution();
	cout << test->maxPoints(input) << endl;
	return 0;
}
