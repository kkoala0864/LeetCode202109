#include <Solution.h>

int main(void) {
	vector<int> input = {57,55,50,60,61,58,63,59,64,60,63};
	Solution *test = new Solution();
	cout << test->maxSubarrayLength(input) << endl;
	return 0;
}
