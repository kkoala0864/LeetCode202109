#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> tops = {2, 1, 2, 4, 2, 2};
	vector<int> bottoms = {5, 2, 6, 2, 3, 2};
	Solution *test = new Solution();
	cout << test->minDominoRotations(tops, bottoms) << endl;
	return 0;
}
