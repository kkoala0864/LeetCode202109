#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 34, 3, 4, 5, 7, 23, 12};
	Solution *test = new Solution();
	cout << test->threeConsecutiveOdds(input) << endl;
	return 0;
}
