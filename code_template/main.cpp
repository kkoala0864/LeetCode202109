#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {5, 1, 1, 2, 0, 0};
	Solution *test = new Solution();
	auto result = test->quick_sort(nums);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;

	nums = {3, 9, 19, 5, 6, 7, 8};
	for (const auto &v : nums)
		cout << v << " ";
	cout << endl;
	cout << test->quick_select(nums, 3) << endl;

	nums = {3, 5, 6, 7, 8, 9, 19};
	for (const auto &v : nums)
		cout << v << " ";
	cout << endl;
	cout << test->binary_search(nums, 8) << endl;

	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	result = test->dijstra(edges, 4, 0);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;

	string text = "ABABDABACDABABCABAB";
	string pattern = "ABABCABAB";

	vector<int> matches = test->KMPsearch(text, pattern);

	cout << "Pattern found at index: ";
	for (int idx : matches) {
		cout << idx << " ";
	}
	cout << endl;

	test->zAlgorithm("aabxaabxcaabxaabxay", "aabxaabxcaabxaabxay");

	return 0;
}
