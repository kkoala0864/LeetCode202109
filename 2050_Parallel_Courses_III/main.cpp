#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 3;
	vector<vector<int>> relation = {{1,3},{2,3}};
	vector<int> times = {3,2,5};
	Solution *test = new Solution();
	cout << test->minimumTime(n, relation, times) << endl;
	return 0;
}
