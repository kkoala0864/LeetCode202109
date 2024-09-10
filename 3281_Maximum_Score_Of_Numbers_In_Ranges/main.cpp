#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,9,2,0};
	int d = 3;
	Solution* test = new Solution();
	cout << test->maxPossibleScore(input, d) << endl;
	return 0;
}

