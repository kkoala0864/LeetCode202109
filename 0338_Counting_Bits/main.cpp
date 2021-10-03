#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	vector<int> result = test->countBits(7);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

