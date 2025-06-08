#include <Solution.h>

int main(void) {
	vector<int> input = {2, 3, 1, 4};
	Solution *test = new Solution();
	cout << test->verifyPreorder(input) << endl;
	return 0;
}
