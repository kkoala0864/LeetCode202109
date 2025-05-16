#include <Solution.h>

int main(void) {
	vector<string> input = {"bab","dab","cab"};
	vector<int> groups = {1,2,2};
	Solution *test = new Solution();
	auto result = test->getWordsInLongestSubsequence(input, groups);
	for (auto &word : result) {
		cout << word << " ";
	}
	cout << endl;
	return 0;
}
