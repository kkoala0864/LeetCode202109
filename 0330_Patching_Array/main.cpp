#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,31,33};
	int n = 2147483647;
	Solution *test = new Solution();
	cout << test->minPatches(input, n) << endl;
	return 0;
}
