#include <Solution.h>

int main(void) {
	vector<int> input = {2,4,5,5,5,5,5,6,6};
	int target = 5;
	Solution *test = new Solution();
	cout << test->isMajorityElement(input, target) << endl;
	return 0;
}
