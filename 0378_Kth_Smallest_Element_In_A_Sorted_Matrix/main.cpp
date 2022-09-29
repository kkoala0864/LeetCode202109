#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	Solution* test = new Solution();
	cout << test->kthSmallest(input, 18) << endl;
	cout << test->kthSmallest2(input, 18) << endl;
	return 0;
}

