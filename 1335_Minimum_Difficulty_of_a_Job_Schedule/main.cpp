#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {6, 5, 4, 3, 2, 1};
	Solution *test = new Solution();
	cout << test->minDifficulty(input, 2) << endl;
	return 0;
}
