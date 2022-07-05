#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,3,7,2,5,8,4,6,0,1};
	Solution* test = new Solution();
	cout << test->longestConsecutive(input) << endl;
	cout << test->longestConsecutive2(input) << endl;
	cout << test->longestConsecutive3(input) << endl;
	cout << test->longestConsecutive4(input) << endl;
	return 0;
}

