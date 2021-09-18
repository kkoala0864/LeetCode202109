#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-1,0,1,2,-1,-4};
	Solution* test = new Solution();
	for (const auto iter : test->threeSum(input)) {
		for (const auto iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	return 0;
}

