#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,2};
	Solution* test = new Solution();
	vector<vector<int>> result = test->subsetsWithDup(input);
	for (const auto& vec : result) {
		for (const auto& iter : vec) {
			cout << iter << " ";
		}
		cout << endl;
	}
	return 0;
}

