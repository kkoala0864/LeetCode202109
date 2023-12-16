#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82};
	Solution* test = new Solution();
	cout << test->countSubarrays(input, 2) << endl;
	return 0;
}

