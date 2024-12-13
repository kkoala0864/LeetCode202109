#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,1,3,4,5,2};
	Solution* test = new Solution();
	cout << test->findScore(input) << endl;
	return 0;
}

