#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {229, 398, 269, 317, 420, 464, 491, 218, 439, 153, 482, 169, 411, 93, 147, 50, 347, 210, 251, 366, 401};
	int result = 973;
	Solution *test = new Solution();
	cout << result << endl;
	cout << test->maximumSum(input) << endl;
	return 0;
}
