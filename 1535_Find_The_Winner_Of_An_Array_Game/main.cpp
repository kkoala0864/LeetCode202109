#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,1,3,5,4,6,7};
	Solution* test = new Solution();
	cout << test->getWinner(input, 2) << endl;
	return 0;
}

