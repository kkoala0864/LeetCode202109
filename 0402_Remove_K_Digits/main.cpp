#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->removeKdigits("112", 1) << endl;
    return 0;
}

