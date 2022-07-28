#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("eat"), t("cat");
	Solution* test = new Solution();
	cout << test->isAnagram(s, t) << endl;
	cout << test->isAnagram2(s, t) << endl;
	cout << test->isAnagram3(s, t) << endl;
	return 0;
}

