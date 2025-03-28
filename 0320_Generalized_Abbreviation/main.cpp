#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "word";
	Solution *test = new Solution();
	auto result = test->generateAbbreviations(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
