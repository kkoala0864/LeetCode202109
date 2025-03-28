#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {88690, 69213};
	Solution *test = new Solution();
	cout << test->minimumTime(input, 90165) << endl;
	return 0;
}
