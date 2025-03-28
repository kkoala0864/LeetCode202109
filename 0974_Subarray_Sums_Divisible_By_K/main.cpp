#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4, 5, 0, -2, -3, 1};
	Solution *test = new Solution();
	cout << test->subarraysDivByK(input, 5) << endl;
	return 0;
}
