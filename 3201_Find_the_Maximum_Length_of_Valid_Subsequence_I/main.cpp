#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,1,1,2,1,2};
	Solution *test = new Solution();
	cout << test->maximumLength(input) << endl;
	return 0;
}
