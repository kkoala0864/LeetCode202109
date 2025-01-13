#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{-7,12,12,13},{-6,19,19,-6},{9,-2,-10,16},{-4,14,-10,-9}};
	Solution* test = new Solution();
	cout << test->maximumAmount(input) << endl;
	return 0;
}

