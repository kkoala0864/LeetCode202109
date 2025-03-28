#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-1, 0, 0, 1, 1, 2};
	Solution *test = new Solution();
	cout << test->longestPath(input, "abacbe") << endl;
	return 0;
}
