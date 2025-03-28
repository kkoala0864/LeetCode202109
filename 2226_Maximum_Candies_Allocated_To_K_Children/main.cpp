#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 6, 4, 10, 10, 1, 1, 2, 2, 2};
	Solution *test = new Solution();
	cout << test->maximumCandies(input, 9) << endl;
	return 0;
}
