#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10000};
	int k = 0;
	Solution *test = new Solution();
	cout << test->maximumBeauty(input, k) << endl;
	return 0;
}
