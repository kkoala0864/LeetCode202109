#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
	Solution* test = new Solution();
	cout << test->search(input, 2) << endl;
	cout << test->search2(input, 2) << endl;
	cout << test->search3(input, 2) << endl;
	return 0;
}

