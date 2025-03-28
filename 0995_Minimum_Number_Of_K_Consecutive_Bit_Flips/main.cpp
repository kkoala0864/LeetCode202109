#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0, 0, 0, 1, 0, 1, 1, 0};
	int k = 3;
	Solution *test = new Solution();
	cout << test->minKBitFlips(input, k) << endl;
	return 0;
}
