#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {19, 12, 14, 6, 10, 18};
	int k = 3;
	Solution *test = new Solution();
	cout << test->maximumScore(input, k) << endl;
	return 0;
}
