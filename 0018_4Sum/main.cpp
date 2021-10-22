#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-2,-1,-1,1,1,2,2};
	Solution* test = new Solution();
	vector<vector<int>> result = test->fourSum(input, 0);
	for (const auto& iter : result) {
		for(const auto& it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}

