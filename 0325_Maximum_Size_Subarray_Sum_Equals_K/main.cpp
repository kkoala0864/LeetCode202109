#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 0, -1};
	Solution *test = new Solution();
	cout << test->maxSubArrayLen(input, -1) << endl;
	return 0;
}
