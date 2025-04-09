#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,3,4,5};
	Solution *test = new Solution();
	cout << test->stoneGame(input) << endl;
	return 0;
}
