#include <Solution.h>

int main(void) {
	vector<int> scores = {5,2,9,8,4};
	vector<vector<int>> edges = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
	Solution *test = new Solution();
	cout << test->maximumScore(scores, edges) << endl;
	return 0;
}
