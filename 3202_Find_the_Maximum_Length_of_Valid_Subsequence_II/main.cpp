#include <Solution.h>

int main(void) {
	vector<int> input = {1,4,2,3,1,4};
	int k = 3;
	Solution *test = new Solution();
	cout << test->maximumLength(input, k) << endl;
	return 0;
}
