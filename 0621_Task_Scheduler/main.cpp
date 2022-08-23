#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<char> input = {'A','A','A','A','A','A','B','C','D','E','F','G'};
	Solution* test = new Solution();
	cout << test->leastInterval(input, 2) << endl;
	return 0;
}

