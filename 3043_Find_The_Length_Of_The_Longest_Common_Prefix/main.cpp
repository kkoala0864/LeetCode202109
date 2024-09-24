#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1,10,100};
	vector<int> input2 = {1000};
	Solution* test = new Solution();
	cout << test->longestCommonPrefix(input1, input2) << endl;
	return 0;
}

