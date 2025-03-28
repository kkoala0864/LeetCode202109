#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 3, 4, 4, 5, 6};
	int k = 4;
	Solution *test = new Solution();
	cout << test->isPossibleDivide(input, k) << endl;
	return 0;
}
