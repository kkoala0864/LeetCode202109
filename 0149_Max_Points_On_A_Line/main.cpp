#include <Solution.h>

int main(void) {
	Solution *test = new Solution();
	vector<vector<int>> input = {{0,0},{4,5},{7,8},{8,9},{5,6},{3,4},{1,1}};
	cout << test->maxPoints(input) << endl;
	return 0;
}
