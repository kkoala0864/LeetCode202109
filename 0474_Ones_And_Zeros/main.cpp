#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"10","0001","111001","1","0"};
	Solution* test = new Solution();
	cout << test->findMaxForm(input, 5, 3) << endl;
	return 0;
}

