#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->numKLenSubstrNoRepeats("havefunonleetcode", 5) << endl;
    return 0;
}

