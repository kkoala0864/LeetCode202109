#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,2,2,0,1};
	Solution* test = new Solution();
	cout << test->findMin(input) << endl;
	return 0;
}

