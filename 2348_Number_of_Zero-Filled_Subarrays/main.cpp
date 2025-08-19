#include <Solution.h>

int main(void) {
	vector<int> input = {1,3,0,0,2,0,0,4};
	Solution *test = new Solution();
	cout << test->zeroFilledSubarray(input) << endl;
	return 0;
}
