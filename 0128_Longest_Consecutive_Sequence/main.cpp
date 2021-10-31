#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9,1,4,7,3,-1,0,5,8,-1,6};
	Solution* test = new Solution();
	cout << test->longestConsecutive(input) << endl;
	cout << test->longestConsecutive2(input) << endl;
	return 0;
}

