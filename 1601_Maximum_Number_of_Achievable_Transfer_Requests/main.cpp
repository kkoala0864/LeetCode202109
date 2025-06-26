#include <Solution.h>

int main(void) {
	int n = 3;
	vector<vector<int>> input = {{1,2},{2,2},{0,0},{1,1},{0,2},{0,0},{2,1},{0,1},{1,0},{2,2},{0,1},{2,0},{2,2}};
	Solution *test = new Solution();
	cout << test->maximumRequests(n, input) << endl;
	return 0;
}
