#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    vector<int> result = test->lexicalOrder(321);
    for (const auto& iter : result) {
	cout << iter << " ";
    }
    cout << endl;
    cout << endl;
    result = test->lexicalOrder2(321);
    for (const auto& iter : result) {
	cout << iter << " ";
    }
    cout << endl;
    return 0;
}

