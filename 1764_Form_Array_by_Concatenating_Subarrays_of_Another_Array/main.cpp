#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> groups = {{1,-1,-1},{3,-2,0}};
	vector<int> nums = {1,-1,0,1,-1,-1,3,-2,0};
	Solution *test = new Solution();
	cout << test->canChoose(groups, nums) << endl;
	return 0;
}
