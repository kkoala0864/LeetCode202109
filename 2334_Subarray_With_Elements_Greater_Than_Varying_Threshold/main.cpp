#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 3, 4, 3, 1};
	int threshold = 6;
	Solution *test = new Solution();
	cout << test->validSubarraySize(input, threshold) << endl;
	return 0;
}
