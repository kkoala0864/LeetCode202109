#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    int input = 30;
    cout << test->countAndSay(input) << endl;
    cout << endl;
    cout << test->countAndSay2(input) << endl;
    return 0;
}

