#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9, 8, 4, 3, 2, 8, 10, 2};
	int k = 8;
	Solution *test = new Solution();
	cout << test->maxFrequency(input, k) << endl;
	return 0;
}
