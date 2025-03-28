#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string beginWord = "red";
	string endWord = "tax";
	vector<string> wordList = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
	Solution *test = new Solution();
	auto result = test->findLadders(beginWord, endWord, wordList);
	for (const auto &vec : result) {
		for (const auto &val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	cout << endl;
	result = test->second(beginWord, endWord, wordList);
	for (const auto &vec : result) {
		for (const auto &val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
