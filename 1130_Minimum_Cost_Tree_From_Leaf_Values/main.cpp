#include <Solution.h>

int main(void) {
	vector<int> arr = {6,2,4};
	Solution *test = new Solution();
	cout << test->mctFromLeafValues(arr) << endl;
	return 0;
}
