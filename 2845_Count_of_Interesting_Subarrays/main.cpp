#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {11,12,21,31};
	int mod = 10;
	int k = 1;
	Solution *test = new Solution();
	cout << test->countInterestingSubarrays(input, mod, k) << endl;
	return 0;
}
