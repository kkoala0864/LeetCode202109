#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,1,0},{1,0,1},{0,1,0}};
	Solution *test = new Solution();
	cout << test->removeOnes(input) << endl;
	return 0;
}
