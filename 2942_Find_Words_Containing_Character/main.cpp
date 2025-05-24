#include <Solution.h>

int main(void) {
	vector<string> input = {"leet","code"};
	char x = 'e';
	Solution *test = new Solution();
	auto result = test->findWordsContaining(input, x);
	for (const auto& word : result) {
		cout << word << endl;
	}
	return 0;
}
