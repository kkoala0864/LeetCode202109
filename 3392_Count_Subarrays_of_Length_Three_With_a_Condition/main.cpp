#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,1,4,1};
	Solution *test = new Solution();
	cout << test->countSubarrays(input) << endl;
	return 0;
}
