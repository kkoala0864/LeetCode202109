#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {100,-100,-300,-300,-300,-100,100};
	Solution* test = new Solution();
	cout << test->maxResult(input, 4) << endl;
	return 0;
}

