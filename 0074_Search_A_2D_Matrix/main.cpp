#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	Solution* test = new Solution();
	cout << test->searchMatrix(input, 3) << endl;
	cout << test->searchMatrix3(input, 3) << endl;
	return 0;
}

