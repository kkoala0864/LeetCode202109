#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,5,3,4,1};
	Solution* test = new Solution();
	cout << test->numTeams(input) << endl;
	return 0;
}

