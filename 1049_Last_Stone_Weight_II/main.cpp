#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,7,4,1,8,1};
	Solution *test = new Solution();
	cout << test->lastStoneWeightII(input) << endl;
	return 0;
}
