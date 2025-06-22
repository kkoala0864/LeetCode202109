#include <Solution.h>

int main(void) {
	vector<int> input = {6,5,8,9,7,1,10,2,3,4};
	int k = 2;
	Solution *test = new Solution();
	cout << test->kEmptySlots(input, k) << endl;
	return 0;
}
