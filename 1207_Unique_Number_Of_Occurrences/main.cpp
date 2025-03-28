#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
	Solution *test = new Solution();
	cout << test->uniqueOccurrences(input) << endl;
	return 0;
}
