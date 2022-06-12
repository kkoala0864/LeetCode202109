#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {8,15,10,20,8};
	Solution* test = new Solution();
	cout << test->distributeCookies(input, 2) << endl;
	return 0;
}

