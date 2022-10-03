#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabaa";
	vector<int> nt = {1,2,3,4,1};
	Solution* test = new Solution();
	cout << test->minCost(input, nt) << endl;
	return 0;
}

