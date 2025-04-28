#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9,5,3,8,4,7,2,7,4,5,4,9,1,4,8,10,8,10,4,7};
	int k = 4;
	Solution *test = new Solution();
	cout << test->countSubarrays(input, k) << endl;
	return 0;
}
