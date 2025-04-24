#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,1,2,2};
	Solution *test = new Solution();
	cout << test->countCompleteSubarrays(input) << endl;
	return 0;
}
