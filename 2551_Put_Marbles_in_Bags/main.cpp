#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,5,1};
	int k = 2;
	Solution *test = new Solution();
	cout << test->putMarbles(input, k) << endl;
	return 0;
}
