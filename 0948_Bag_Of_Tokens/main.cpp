#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {100};
	Solution *test = new Solution();
	cout << test->bagOfTokensScore(input, 50) << endl;
	return 0;
}
