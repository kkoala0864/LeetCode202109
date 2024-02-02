#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    cout << test->reverseVowels("leetcode") << endl;
    cout << test->reverseVowels2("leetcode") << endl;
    return 0;
}

