#include <Solution.h>

int main(void) {
	vector<vector<string>> input = {{"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}};
	Solution *test = new Solution();
	vector<int> result = test->peopleIndexes(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
