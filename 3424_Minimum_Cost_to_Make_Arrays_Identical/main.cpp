#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> v1 = {3,-4};
	vector<int> v2 = {4, 5};
	int k = 29;
	Solution *test = new Solution();
	cout << test->minCost(v1, v2, k) << endl;
	return 0;
}
