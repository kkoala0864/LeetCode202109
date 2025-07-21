#include <Solution.h>

int main(void) {
	vector<vector<string>> input = {{"a"},{"c"},{"d"},{"a","b"},{"c","b"},{"d","a"}};
	Solution *test = new Solution();
	auto result = test->deleteDuplicateFolder(input);
	for (const auto& v : result) {
		for (const auto& c : v) cout << c << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}
