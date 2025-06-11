#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,2,2,5,0};
	Solution *test = new Solution();
	cout << test->waysToSplit(input) << endl;
	return 0;
}
