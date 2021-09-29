#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'a'}};
	vector<string> words = {"a"};
	Solution* test = new Solution();
	vector<string> result = test->findWords(input, words);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

