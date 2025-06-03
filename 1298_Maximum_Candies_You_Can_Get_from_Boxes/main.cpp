#include <Solution.h>

int main(void) {
	vector<int> status = {1,1,1};
	vector<int> candies = {100,1,100};
	vector<vector<int>> keys = {{},{0,2},{}};
	vector<vector<int>> containedBoxes = {{},{},{}};
	vector<int> initialBoxes = {1};
	Solution *test = new Solution();
	cout << test->maxCandies(status, candies, keys, containedBoxes, initialBoxes) << endl;
	return 0;
}
