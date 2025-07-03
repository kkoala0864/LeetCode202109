#include <Solution.h>

int main(void) {
	vector<int> input = {6,4,14,6,8,13,9,7,10,6,12};
	int d = 2;
	Solution *test = new Solution();
	cout << test->maxJumps(input, d) << endl;
	return 0;
}
