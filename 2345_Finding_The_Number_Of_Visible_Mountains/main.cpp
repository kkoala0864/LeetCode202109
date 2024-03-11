#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3,19},{39,7},{15,39},{23,13},{8,28},{2,26},{38,15},{38,7},{16,17}};
	Solution* test = new Solution();
	cout << test->visibleMountains(input) << endl;
	return 0;
}

