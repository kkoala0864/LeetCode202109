#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
	Solution* test = new Solution();
	cout << test->longestOnes(input, 3) << endl;
	return 0;
}

