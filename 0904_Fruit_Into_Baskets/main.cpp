#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,1,2,2};
	Solution* test = new Solution();
	cout << test->totalFruit(input) << endl;
	return 0;
}

