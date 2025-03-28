#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0, 1, 0, 1};
	int k = 3;
	Solution *test = new Solution();
	cout << test->numberOfAlternatingGroups(input, k) << endl;
	return 0;
}
