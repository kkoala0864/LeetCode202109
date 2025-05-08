#include <Solution.h>

int main(void) {
	// ["AutocompleteSystem","input","input","input","input","input","input","input","input","input","input","input","input","input","input"]
	// [[["abc","abbc","a"],[3,3,3]],["b"],["c"],["#"],["b"],["c"],["#"],["a"],["b"],["c"],["#"],["a"],["b"],["c"],["#"]]
	// [null,[],[],[],["bc"],["bc"],[],["a","abbc","abc"],["abbc","abc"],["abc"],[],["abc","a","abbc"],["abc","abbc"],["abc"],[]]
	vector<string> sentences = {"abc", "abbc", "a"};
	vector<int> times = {3,3,3};
	AutocompleteSystem* test = new AutocompleteSystem(sentences, times);
	string input = "bc#bc#abc#abc#";
	for (const auto& c : input) {
		auto result = test->input(c);
		cout << c << " >> ";
		for (const auto& s : result) {
			cout << s << " | ";
		}
		cout << endl;
	}
	return 0;
}
