#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 3;
	vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
	vector<double> succProb = {0.5, 0.5, 0.2};
	int start = 0;
	int end = 2;
	Solution *test = new Solution();
	cout << test->maxProbability(n, edges, succProb, start, end) << endl;
	return 0;
}
