#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->uniquePaths(10, 10) << endl;
    cout << test->uniquePaths2(10, 10) << endl;
    return 0;
}

