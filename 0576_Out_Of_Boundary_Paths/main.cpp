#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->findPaths(1,3,3,0,1) << endl;
    return 0;
}

