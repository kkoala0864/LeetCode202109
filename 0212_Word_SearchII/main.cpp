#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
	vector<string> words = {"oath", "pea", "eat", "rain"};
	Solution *test = new Solution();
	vector<string> result = test->findWords(input, words);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	vector<string> result2 = test->findWords2(input, words);
	for (const auto &iter : result2) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
