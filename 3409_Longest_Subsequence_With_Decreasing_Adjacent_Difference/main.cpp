#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,8,8,8,1};
	Solution* test = new Solution();
	cout << test->longestSubsequence(input) << endl;
	return 0;
}

