#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 0, 2};
	Solution *test = new Solution();
	cout << test->candy(input) << endl;
	cout << test->twoArray(input) << endl;
	return 0;
}
