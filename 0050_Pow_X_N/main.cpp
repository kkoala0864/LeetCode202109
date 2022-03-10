#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->myPow(2.00000, -2) << endl;
    cout << test->myPow2(2.00000, -2) << endl;
    return 0;
}

