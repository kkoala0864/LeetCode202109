#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->addBinary("11", "1") << endl;
    cout << test->addBinary2("11", "1") << endl;
    return 0;
}

