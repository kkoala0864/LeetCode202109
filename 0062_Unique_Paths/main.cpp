#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->uniquePaths(3, 7) << endl;
    cout << test->uniquePaths4(3, 7) << endl;
    return 0;
}

