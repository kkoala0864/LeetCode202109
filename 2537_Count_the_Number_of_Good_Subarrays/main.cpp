#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,1,4,3,2,2,4};
	int k = 2;
	Solution *test = new Solution();
	cout << test->countGood(input, k) << endl;
	return 0;
}
