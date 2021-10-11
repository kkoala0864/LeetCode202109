#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> inupt = {1};
	Solution* test = new Solution();
	cout << test->searchInsert(inupt, 0) << endl;
	return 0;
}

