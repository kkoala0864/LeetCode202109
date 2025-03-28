#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 8, 9, 10, 12, 13, 20};
	vector<int> costs = {3, 12, 54};
	Solution *test = new Solution();
	cout << test->mincostTickets(input, costs) << endl;
	return 0;
}
