#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"i", "love", "leetcode", "i", "love", "coding"};
	Solution *test = new Solution();
	auto result = test->topKFrequent(input, 2);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	result = test->topKFrequent2(input, 2);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
