#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> queries = {"bbb", "cc"};
	vector<string> words = {"a", "aa", "aaa", "aaaa"};
	Solution *test = new Solution();
	auto result = test->numSmallerByFrequency(queries, words);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
