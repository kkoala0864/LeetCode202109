#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->rangeBitwiseAnd(10, 16) << endl;
    return 0;
}

