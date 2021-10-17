#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,5,2,1,2};
	Solution* test = new Solution();
	vector<vector<int>> result = test->combinationSum2(input, 5);
	for (const auto& set : result) {
		for (const auto& iter : set) {
			cout << iter << " ";
		}
		cout << endl;
	}
	return 0;
}

