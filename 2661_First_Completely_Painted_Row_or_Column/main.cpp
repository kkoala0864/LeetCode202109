#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> arr = {1, 3, 4, 2};
	vector<vector<int>> mat = {{1, 4}, {2, 3}};
	Solution *test = new Solution();
	cout << test->firstCompleteIndex(arr, mat) << endl;
	return 0;
}
