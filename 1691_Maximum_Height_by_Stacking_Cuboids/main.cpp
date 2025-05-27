#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{50,45,20},{95,37,53},{45,23,12}};
	Solution *test = new Solution();
	cout << test->maxHeight(input) << endl;
	return 0;
}
