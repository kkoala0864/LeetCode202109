#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,3,6,16,8,2};
	Solution* test = new Solution();
	cout << test->longestSquareStreak(input) << endl;
	return 0;
}

