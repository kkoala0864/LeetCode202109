#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> scores = {4, 5, 6, 5};
	vector<int> ages = {2, 1, 2, 1};
	Solution *test = new Solution();
	cout << test->bestTeamScore(scores, ages) << endl;
	return 0;
}
