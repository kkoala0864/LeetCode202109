#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
	vector<bool> hasApple = {false,false,true,false,true,true,false};
	Solution* test = new Solution();
	cout << test->minTime(7, edges, hasApple) << endl;
	return 0;
}

