#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->removeKdigits("1432219", 3) << endl;
    cout << test->removeKdigits2("1432219", 3) << endl;
    return 0;
}

