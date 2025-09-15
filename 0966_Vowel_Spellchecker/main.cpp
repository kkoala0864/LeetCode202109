#include <Solution.h>

int main(void) {
	vector<string> wordlist = {"KiTe","kite","hare","Hare"};
	vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
	Solution *test = new Solution();
	auto result = test->spellchecker(wordlist, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
