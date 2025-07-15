#include <Solution.h>

int main(void) {
	vector<vector<int>> g = {{0,2},{0,3},{3,1}};
	string label = "bbac";
	int n = 4;
	Solution *test = new Solution();
	cout << test->maxLen(n, g, label) << endl;
	return 0;
}
