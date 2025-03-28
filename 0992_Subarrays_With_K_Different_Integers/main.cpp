#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 1, 2, 3};
	int k = 2;
	Solution *test = new Solution();
	cout << test->subarraysWithKDistinct(input, k) << endl;
	return 0;
}
