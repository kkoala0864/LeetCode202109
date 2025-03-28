#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
	Solution *test = new Solution();
	auto result = test->removeSubfolders(input);
	for (const auto &v : result) {
		cout << v << endl;
	}
	return 0;
}
