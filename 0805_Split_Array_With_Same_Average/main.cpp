#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4,5,6,7,8};
	Solution *test = new Solution();
	cout << test->splitArraySameAverage(input) << endl;
	return 0;
}
