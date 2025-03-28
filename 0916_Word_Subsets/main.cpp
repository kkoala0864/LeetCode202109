#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input1 = {"amazon", "apple", "facebook", "google", "leetcode"};
	vector<string> input2 = {"l", "e"};
	Solution *test = new Solution();
	auto result = test->wordSubsets(input1, input2);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
