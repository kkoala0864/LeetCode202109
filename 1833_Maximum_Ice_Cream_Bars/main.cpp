#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 3, 2, 4, 1};
	Solution *test = new Solution();
	cout << test->maxIceCream(input, 7) << endl;
	return 0;
}
