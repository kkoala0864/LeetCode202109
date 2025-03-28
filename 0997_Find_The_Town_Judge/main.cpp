#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 3}, {2, 3}, {3, 1}};
	Solution *test = new Solution();
	cout << test->findJudge(3, input) << endl;
	cout << test->findJudge2(3, input) << endl;
	cout << test->findJudge3(3, input) << endl;
	return 0;
}
