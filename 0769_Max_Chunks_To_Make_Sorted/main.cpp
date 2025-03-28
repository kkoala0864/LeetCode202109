#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 0, 2, 3, 4};
	Solution *test = new Solution();
	cout << test->maxChunksToSorted(input) << endl;
	cout << test->maxChunksToSortedStack(input) << endl;
	return 0;
}
