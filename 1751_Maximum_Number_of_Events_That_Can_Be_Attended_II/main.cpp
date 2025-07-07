#include <Solution.h>

int main(void) {
	vector<vector<int>> events = {{1,2,10},{1,2,4}};
	int k = 2;
	Solution *test = new Solution();
	cout << test->maxValue(events, k) << endl;
	return 0;
}
