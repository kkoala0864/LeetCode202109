#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,6},{2,3}};
	Solution *test = new Solution();
	cout << test->earliestTime(input) << endl;
	return 0;
}
