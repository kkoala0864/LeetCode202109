#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
	Solution* test = new Solution();
	cout << test->isBipartite(input) << endl;
	cout << test->isBipartite2(input) << endl;
	return 0;
}

