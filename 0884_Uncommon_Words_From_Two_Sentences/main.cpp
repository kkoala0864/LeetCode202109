#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "this apple is sweet";
	string s2 = "this apple is sour";
	Solution *test = new Solution();
	auto result = test->uncommonFromSentences(s1, s2);
	for (const auto &i : result)
		cout << i << " ";
	cout << endl;
	return 0;
}
