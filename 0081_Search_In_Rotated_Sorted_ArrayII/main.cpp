#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,0,1,1,1};
	Solution* test = new Solution();
	cout << test->search(input, 0) << endl;
	return 0;
}

