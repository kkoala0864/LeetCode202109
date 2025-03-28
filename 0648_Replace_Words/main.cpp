#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"cat", "bat", "rat"};
	string sentence = "the cattle was rattled by the battery";
	Solution *test = new Solution();
	cout << test->replaceWords(input, sentence) << endl;
	return 0;
}
