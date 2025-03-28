#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 1, 1};
	Solution *test = new Solution();
	cout << test->minimumIndex(input) << endl;
	return 0;
}
