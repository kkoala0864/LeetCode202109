#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->isPowerOfThree(27) << endl;
    cout << test->isPowerOfThree2(27) << endl;
    return 0;
}

