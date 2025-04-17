#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,1,2,2,2,1,3};
	int k = 2;
	Solution *test = new Solution();
	cout << test->countPairs(input, k) << endl;
	return 0;
}
