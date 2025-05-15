#include <Solution.h>

int main(void) {
	vector<string> input = {"e","a","b"};
	vector<int> groups = {0,0,1};
	Solution *test = new Solution();
	auto result = test->getLongestSubsequence(input, groups);
	for (const auto &s : result) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
