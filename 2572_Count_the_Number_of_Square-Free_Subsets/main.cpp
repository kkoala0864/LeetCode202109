#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,24,2,16,18,3,26,29,16,6,1,28,18,14,12,1,16,20,27,6,22};
	Solution *test = new Solution();
	cout << test->squareFreeSubsets(input) << endl;
	return 0;
}
