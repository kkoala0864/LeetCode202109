#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> indices = {0, 2};
	vector<string> sources = {"a", "cd"};
	vector<string> targets = {"eee", "ffff"};
	Solution *test = new Solution();
	cout << test->findReplaceString("abcd", indices, sources, targets) << endl;
	cout << test->findReplaceString2("abcd", indices, sources, targets) << endl;
	return 0;
}
