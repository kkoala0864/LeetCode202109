#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,5,7,8,5,3,4,2,1};
	Solution* test = new Solution();
	cout << test->longestSubsequence(input, -2) << endl;
	return 0;
}

