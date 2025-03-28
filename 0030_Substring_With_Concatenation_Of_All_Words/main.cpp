#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "barfoothefoobarman";
	vector<string> words = {"foo", "bar"};
	Solution *test = new Solution();
	auto result = test->findSubstring2(input, words);
	for (const auto &str : result) {
		cout << str << " ";
	}
	cout << endl;
	/*
	result = test->findSubstring2(input, words);
	for (const auto& str : result) {
	        cout << str << " ";
	}
	cout << endl;
	*/
	return 0;
}
