#include <Solution.h>

int main(void) {
	vector<int> input = {2,3,5};
	int target = 10;
	Solution *test = new Solution();
	cout << test->findBestValue(input, target) << endl;
	return 0;
}
