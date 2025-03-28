#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{-1, 3, 4}, {-1, -1, -1}, {3, -1, -1}};
	Solution *test = new Solution();
	cout << test->sumRemoteness(input) << endl;
	return 0;
}
