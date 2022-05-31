#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "wordgoodgoodgoodbestword";
	vector<string> words = {"word","good","best","good"};
	Solution* test = new Solution();
	auto result = test->findSubstring(input, words);
	for (const auto& str : result) {
		cout << str << " ";
	}
	cout << endl;
	return 0;
}

