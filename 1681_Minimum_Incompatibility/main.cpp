#include <Solution.h>

int main(void) {
	vector<int> input = {7,3,16,15,1,13,1,2,14,5,3,10,6,2,7,15};
	int k = 8;
	Solution *test = new Solution();
	cout << test->minimumIncompatibility(input, k) << endl;
	return 0;
}
