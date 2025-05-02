#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,10},{2,2},{3,4}};
	int changeTime = 6;
	int numLaps = 5;
	Solution *test = new Solution();
	cout << test->minimumFinishTime(input, changeTime, numLaps) << endl;
	return 0;
}
