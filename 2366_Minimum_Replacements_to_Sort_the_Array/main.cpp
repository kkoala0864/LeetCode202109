#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7,6,15,6,11,14,10};
	Solution *test = new Solution();
	cout << test->minimumReplacement(input) << endl;
	return 0;
}
