#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->numTrees(4) << endl;
    cout << test->numTrees2(3) << endl;
    return 0;
}

