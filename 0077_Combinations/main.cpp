#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<vector<int>> result = test->combine(4, 2);
    for (const auto& iter : result) {
	for (const auto& ele : iter) {
		cout << ele << " ";
	}
	cout << endl;
    }
    cout << endl;
    result = test->combine2(4, 2);
    for (const auto& iter : result) {
	for (const auto& ele : iter) {
		cout << ele << " ";
	}
	cout << endl;
    }
    return 0;
}

