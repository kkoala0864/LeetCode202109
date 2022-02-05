#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->rangeBitwiseAnd(5, 7) << endl;
    cout << test->rangeBitwiseAnd2(5, 7) << endl;
    return 0;
}

