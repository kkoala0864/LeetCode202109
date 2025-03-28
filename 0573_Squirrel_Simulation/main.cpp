#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> tree = {2, 2};
	vector<int> squirrel = {4, 4};
	vector<vector<int>> nuts = {{3, 0}, {2, 5}};
	Solution *test = new Solution();
	cout << test->minDistance(5, 7, tree, squirrel, nuts) << endl;
	return 0;
}
