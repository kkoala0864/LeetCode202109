#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{515,563},{451,713},{537,709},{343,819},{855,779},{457,60},{650,359},{631,42}};
	Solution* test = new Solution();
	cout << test->twoCitySchedCost(input) << endl;
	return 0;
}

