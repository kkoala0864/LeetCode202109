#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,1,0};
	Solution* test = new Solution();
	cout << test->rob(input) << endl;
	return 0;
}

