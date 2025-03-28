#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 4, 2, 4};
	Solution *test = new Solution();
	cout << test->continuousSubarrays(input) << endl;
	return 0;
}
