#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> im = {1, 2};
	vector<int> in = {3, 4};
	Solution *test = new Solution();
	cout << test->findMedianSortedArrays(im, in) << endl;
	return 0;
}
