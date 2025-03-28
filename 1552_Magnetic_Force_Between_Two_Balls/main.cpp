#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 4, 7};
	int m = 3;
	Solution *test = new Solution();
	cout << test->maxDistance(input, m) << endl;
	return 0;
}
