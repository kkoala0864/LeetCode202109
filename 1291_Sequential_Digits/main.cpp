#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    auto result = test->sequentialDigits(100, 300);
    for (const auto& iter : result) {
	cout << iter << " ";
    }
    cout << endl;
    result = test->sequentialDigits2(100, 300);
    for (const auto& iter : result) {
	cout << iter << " ";
    }
    cout << endl;
    return 0;
}

