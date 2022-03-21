#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->nthUglyNumber(469) << endl;
    cout << test->nthUglyNumber2(469) << endl;
    return 0;
}

