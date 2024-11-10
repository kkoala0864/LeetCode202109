#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {32,1,2,81,76,58};
	int k = 125;
	Solution* test = new Solution();
	cout << test->minimumSubarrayLength(input, k) << endl;
	return 0;
}

