#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,7,7,8,8,10};
	Solution* test = new Solution();
	vector<int> result = test->searchRange(input, 6);
	cout << result[0] << " : " << result[1] << endl;
	return 0;
}

