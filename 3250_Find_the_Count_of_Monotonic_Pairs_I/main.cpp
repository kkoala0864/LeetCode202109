#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,2};
	Solution *test = new Solution();
	cout << test->countOfPairs(input) << endl;
	return 0;
}
