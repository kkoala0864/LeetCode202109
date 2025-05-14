#include <Solution.h>

int main(void) {
	string input = "x";
	int t = 40;
	vector<int> nums = {6,6,8,1,9,9,10,3,9,4,8,5,2,8,10,2,6,8,2,3,3,7,2,6,4,2};
	Solution *test = new Solution();
	cout << test->lengthAfterTransformations(input, t, nums) << endl;
	return 0;
}
