#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{3,1},{1,3},{1,1}};
	Solution *test = new Solution();
	cout << test->numberOfPairs(input) << endl;
	return 0;
}
