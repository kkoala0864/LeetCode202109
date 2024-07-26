#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 4;
	vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
	int distanceThreshold = 4;
	Solution* test = new Solution();
	cout << test->findTheCity(n, edges, distanceThreshold) << endl;
	return 0;
}

