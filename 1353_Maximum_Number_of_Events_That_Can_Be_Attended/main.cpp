#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,2},{2,3},{3,4}};
	Solution *test = new Solution();
	cout << test->maxEvents(input) << endl;
	return 0;
}
