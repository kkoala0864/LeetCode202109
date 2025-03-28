#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {20, 1, 15, 3, 10, 5, 8};
	Solution *test = new Solution();
	cout << test->longestArithSeqLength(input) << endl;
	return 0;
}
