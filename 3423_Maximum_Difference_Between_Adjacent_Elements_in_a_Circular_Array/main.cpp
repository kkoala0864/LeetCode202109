#include <Solution.h>

int main(void) {
	vector<int> input = {1, 2, 4};
	Solution *test = new Solution();
	cout << test->maxAdjacentDistance(input) << endl;
	return 0;
}
