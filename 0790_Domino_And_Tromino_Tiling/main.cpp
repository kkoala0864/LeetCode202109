#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->numTilings(3) << endl;
    cout << test->numTilings2(3) << endl;
    return 0;
}

