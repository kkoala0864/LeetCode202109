#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-1,3,-4,-7};
	int k = 2;
	Solution* test = new Solution();
	cout << test->maximumEnergy(input, k) << endl;
	return 0;
}

