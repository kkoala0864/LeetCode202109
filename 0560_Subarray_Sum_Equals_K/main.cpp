#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 1, 1};
	Solution *test = new Solution();
	cout << test->subarraySum(input, 2) << endl;
	cout << test->subarraySum2(input, 2) << endl;
	return 0;
}
