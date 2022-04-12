#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->reverse(1534236469) << endl;
    cout << test->reverse2(1534236469) << endl;
    return 0;
}

