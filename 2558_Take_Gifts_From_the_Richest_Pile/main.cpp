#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {25,64,9,4,100};
	int k = 4;
	Solution* test = new Solution();
	cout << test->pickGifts(input, k) << endl;
	return 0;
}

