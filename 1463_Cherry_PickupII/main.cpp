#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
	Solution* test = new Solution();
	//cout << test->cherryPickup(input) << endl;
	cout << test->cherryPickup2(input) << endl;
	return 0;
}

