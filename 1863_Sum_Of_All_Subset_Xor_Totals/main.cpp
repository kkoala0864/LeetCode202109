#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 1, 6};
	Solution *test = new Solution();
	cout << test->subsetXORSum(input) << endl;
	return 0;
}
