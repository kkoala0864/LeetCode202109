#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 2, 3, 4, 3};
	int k = 3;
	Solution *test = new Solution();
	cout << test->shareCandies(input, k) << endl;
	return 0;
}
