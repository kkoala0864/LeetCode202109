#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> dictionary = {"cat","cats","and","sand","dog"};
	Solution* test = new Solution();
	auto result = test->wordBreak("catsanddog", dictionary);
	for (const auto& s : result) {
		cout << s << endl;
	}
	result = test->wordBreak2("catsanddog", dictionary);
	for (const auto& s : result) {
		cout << s << endl;
	}
	return 0;
}

