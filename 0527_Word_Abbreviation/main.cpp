#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
	Solution *test = new Solution();
	auto result = test->wordsAbbreviation(input);
	for (const auto &word : result) {
		cout << word << " ";
	}
	cout << endl;
	return 0;
}
