#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4, 8, 10, 240};
	Solution* test = new Solution();
	vector<int> result = test->largestDivisibleSubset(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

