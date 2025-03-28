#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 5, 6, 11, 13, 15, 17, 28};
	Solution *test = new Solution();
	cout << test->lenLongestFibSubseq(input) << endl;
	return 0;
}
