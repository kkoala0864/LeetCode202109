#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{5,4},{6,4},{6,7},{2,3}};
	Solution* test = new Solution();
	cout << test->maxEnvelopes(input) << endl;
	cout << test->maxEnvelopes2(input) << endl;
	return 0;
}

