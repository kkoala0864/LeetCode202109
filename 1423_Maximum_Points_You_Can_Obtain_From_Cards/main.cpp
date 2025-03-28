#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 4, 5, 6, 1};
	Solution *test = new Solution();
	cout << test->maxScore(input, 3) << endl;
	return 0;
}
