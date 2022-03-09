#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<string> result = test->generateParenthesis(3);
    for (const auto& iter : result) {
	cout << iter << endl;
    }
    cout << endl;
    result = test->generateParenthesis2(3);
    for (const auto& iter : result) {
	cout << iter << endl;
    }
    return 0;
}

