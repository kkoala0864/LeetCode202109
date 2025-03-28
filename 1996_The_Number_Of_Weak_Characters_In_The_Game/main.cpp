#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2, 4}, {2, 5}, {3, 6}, {3, 7}, {3, 8}};
	// vector<vector<int>> input = {{1,5},{10,4},{4,3}};
	Solution *test = new Solution();
	cout << test->numberOfWeakCharacters(input) << endl;
	return 0;
}
