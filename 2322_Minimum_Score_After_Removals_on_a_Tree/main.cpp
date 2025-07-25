#include <Solution.h>

int main(void) {
	vector<int> input = {1,5,5,4,11};
	vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
	Solution *test = new Solution();
	cout << test->minimumScore(input, edges) << endl;
	return 0;
}
