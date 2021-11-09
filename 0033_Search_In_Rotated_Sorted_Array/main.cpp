#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,5,6,7,0,1,2};
	Solution* test = new Solution();
	cout << test->search(input, 0) << endl;
	cout << test->search2(input, 0) << endl;
	return 0;
}

