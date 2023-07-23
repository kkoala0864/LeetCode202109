#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->parseTernary("F?1:T?4:5") << endl;
    return 0;
}

