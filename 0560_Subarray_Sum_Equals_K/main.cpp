#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,0,0,0,0,0,0,0,0,0};
	Solution* test = new Solution();
	cout << test->subarraySum(input, 0) << endl;
	return 0;
}
