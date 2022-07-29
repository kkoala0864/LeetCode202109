#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->titleToNumber("FXSHRXW") << endl;
    cout << test->titleToNumber2("FXSHRXW") << endl;
    return 0;
}

