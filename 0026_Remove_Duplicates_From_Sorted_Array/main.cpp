#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 2, 3, 4, 5, 5, 6};
	Solution* test = new Solution();
	//cout << test->removeDuplicates(input) << endl;
	cout << test->removeDuplicates2(input) << endl;
	return 0;
}

