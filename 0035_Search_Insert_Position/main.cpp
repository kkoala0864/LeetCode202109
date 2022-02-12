#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> inupt = {1,2,3,6};
	Solution* test = new Solution();
	cout << test->searchInsert(inupt, 0) << endl;
	cout << test->searchInsert2(inupt, 0) << endl;
	return 0;
}

