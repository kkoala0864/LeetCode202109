#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,1,5,2,6,3};
	vector<vector<int>> seq = {{5,2,6,3},{4,1,5,2}};
	Solution* test = new Solution();
	cout << test->sequenceReconstruction(input, seq) << endl;
	return 0;
}

