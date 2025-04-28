#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> n1 = {-2,-1,0,1,2};
	vector<int> n2 = {-3,-1,2,4,5};
	int k = 3;
	Solution *test = new Solution();
	cout << test->kthSmallestProduct(n1, n2, k) << endl;
	return 0;
}
