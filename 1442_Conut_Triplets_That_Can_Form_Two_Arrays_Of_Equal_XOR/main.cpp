#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,1,6,7};
	Solution* test = new Solution();
	cout << test->countTriplets(input) << endl;
	return 0;
}

