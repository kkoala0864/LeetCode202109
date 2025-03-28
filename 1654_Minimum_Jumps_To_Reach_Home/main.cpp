#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> forbid = {14, 4, 18, 1, 15};
	Solution *test = new Solution();
	cout << test->minimumJumps(forbid, 3, 15, 9) << endl;
	return 0;
}
