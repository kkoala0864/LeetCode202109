#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {-36,-72,-41,69,-14,44,58,-47,45};
	string s = "LLLRRRLRL";
	int d = 2;
	Solution *test = new Solution();
	cout << test->sumDistance(nums, s, d) << endl;
	return 0;
}
