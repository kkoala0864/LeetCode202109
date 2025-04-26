#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {35054,398719,945315,945315,820417,945315,35054,945315,171832,945315,35054,109750,790964,441974,552913};
	int minK = 35054;
	int maxK = 945315;
	Solution *test = new Solution();
	cout << test->countSubarrays(input, minK, maxK) << endl;
	return 0;
}
