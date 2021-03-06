#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"a","b","c","ab","ac","aa"};
	Solution* test = new Solution();
	vector<vector<int>> result = test->palindromePairs(input);
	for (const auto& iter : result) {
		cout << "[" << iter[0] << " : " << iter[1] << "]" << endl;
	}
	return 0;
}

