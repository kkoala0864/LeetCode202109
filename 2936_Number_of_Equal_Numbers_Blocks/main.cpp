#include <Solution.h>

int main(void) {
	vector<int> input = {3,3,3,3,3};
	BigArray *bigArray = new BigArray(input);
	Solution *test = new Solution();
	cout << test->countBlocks(bigArray) << endl;
	return 0;
}
