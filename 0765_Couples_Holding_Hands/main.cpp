#include <Solution.h>

int main(void) {
	vector<int> input = {1,4,0,5,8,7,6,3,2,9};
	Solution *test = new Solution();
	cout << test->minSwapsCouples(input) << endl;
	return 0;
}
