#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    auto result = test->findAnagrams("abab", "ab");
    for (const auto& iter : result) {
	cout << iter << " ";
    }
    cout << endl;
    return 0;
}

