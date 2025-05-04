#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{2,1},{3,4},{5,6}};
	Solution *test = new Solution();
	cout << test->numEquivDominoPairs(input) << endl;
	return 0;
}
