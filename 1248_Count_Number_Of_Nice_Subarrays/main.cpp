#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,2,1,1};
	int k = 3;
	Solution* test = new Solution();
	cout << test->numberOfSubarrays(input, k) << endl;
	return 0;
}

