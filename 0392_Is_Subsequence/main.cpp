#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("axc");
	string t("ahbgdc");
    Solution* test = new Solution();
    cout << test->isSubsequence(s, t) << endl;
    return 0;
}

