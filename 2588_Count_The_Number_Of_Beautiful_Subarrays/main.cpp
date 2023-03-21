#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,10,4};
	Solution* test = new Solution();
	cout << test->beautifulSubarrays(input) << endl;
	return 0;
}

