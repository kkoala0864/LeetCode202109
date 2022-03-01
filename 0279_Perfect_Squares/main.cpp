#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->numSquares(13) << endl;
    cout << test->numSquares2(13) << endl;
    return 0;
}

