#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {6,3,4,3,5,3};
	int mean = 1;
	int n = 6;
	Solution* test = new Solution();
	auto result = test->missingRolls(input, mean, n);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

