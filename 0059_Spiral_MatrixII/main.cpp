#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> result = test->generateMatrix(3);
    for (const auto& iter : result) {
	for (const auto& it : iter) {
		cout << it << " ";
	}
	cout << endl;
    }
    return 0;
}

