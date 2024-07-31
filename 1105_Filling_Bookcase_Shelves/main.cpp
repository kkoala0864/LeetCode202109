#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
	int shelfWidth = 4;
	Solution* test = new Solution();
	cout << test->minHeightShelves(input, shelfWidth) << endl;
	return 0;
}

