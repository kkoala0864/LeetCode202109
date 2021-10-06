#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,1,2,2,3,0,4,2};
	Solution* test = new Solution();
	cout << test->removeElement(input, 2) << endl;
	for (const auto& iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

