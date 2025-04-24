#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> heights = {6,4,8,5,2,7};
	vector<vector<int>> queries = {{0,1},{0,3},{2,4},{3,4},{2,2}};
	Solution *test = new Solution();
	auto result = test->leftmostBuildingQueries(heights, queries);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
