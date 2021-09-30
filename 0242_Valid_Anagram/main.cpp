#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("eat"), t("cat");
	Solution* test = new Solution();
	cout << test->isAnagram(s, t) << endl;
	return 0;
}

