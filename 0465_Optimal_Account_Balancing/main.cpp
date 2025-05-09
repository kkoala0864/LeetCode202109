#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,1,2},{1,2,1},{1,3,1}};
	Solution *test = new Solution();
	cout << test->minTransfers(input) << endl;
	return 0;
}
