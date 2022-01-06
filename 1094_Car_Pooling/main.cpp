#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,1,5},{3,3,7}};
	Solution* test = new Solution();
	cout << test->carPooling(input, 5) << endl;
	return 0;
}

