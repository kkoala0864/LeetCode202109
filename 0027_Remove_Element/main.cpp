#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0};
	Solution* test = new Solution();
	cout << test->removeElement2(input, 0) << endl;
	for (const auto& iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

