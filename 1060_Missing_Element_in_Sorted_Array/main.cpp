#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {4,7,9,10};
	int k = 3;
	Solution *test = new Solution();
	cout << test->missingElement(nums, k) << endl;
	return 0;
}
