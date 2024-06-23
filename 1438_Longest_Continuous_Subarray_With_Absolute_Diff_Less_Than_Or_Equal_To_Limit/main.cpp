#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10,1,2,4,7,2};
	int limit = 5;
	Solution* test = new Solution();
	cout << test->longestSubarray(input, limit) << endl;
	return 0;
}

