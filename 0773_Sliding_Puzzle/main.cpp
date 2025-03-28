#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3, 2, 4}, {1, 5, 0}};
	Solution *test = new Solution();
	cout << test->slidingPuzzle(input) << endl;
	return 0;
}
