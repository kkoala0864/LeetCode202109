#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->numWaterBottles(15, 4) << endl;
    return 0;
}

