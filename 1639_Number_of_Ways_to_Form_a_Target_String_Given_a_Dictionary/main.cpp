#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"acca","bbbb","caca"};
	string target = "aba";
	Solution* test = new Solution();
	cout << test->numWays(input, target) << endl;
	return 0;
}

