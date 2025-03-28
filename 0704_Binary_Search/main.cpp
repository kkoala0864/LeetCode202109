#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-1, 0, 3, 5, 9, 12};
	Solution *test = new Solution();
	cout << test->search(input, 2) << endl;
	return 0;
}
