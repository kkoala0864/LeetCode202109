#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> img1 = {{1,1,0},{0,1,0},{0,1,0}};
	vector<vector<int>> img2 = {{0,0,0},{0,1,1},{0,0,1}};
	Solution* test = new Solution();
	cout << test->largestOverlap(img1, img2) << endl;
	return 0;
}

