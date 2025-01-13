#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 5;
	vector<vector<int>> input = {{1,0,1},{2,0,2},{3,0,1},{4,3,1},{2,1,1}};
	int threshold = 2;
	Solution* test = new Solution();
	cout << test->minMaxWeight(n, input, threshold) << endl;
	return 0;
}

