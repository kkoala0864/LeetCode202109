#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> n1 = {4,0,1,3,2};
	vector<int> n2 = {4,1,0,2,3};
	Solution *test = new Solution();
	cout << test->goodTriplets(n1, n2) << endl;
	return 0;
}
