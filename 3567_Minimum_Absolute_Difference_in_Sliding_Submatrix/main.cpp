#include <Solution.h>

int main(void) {
	vector<vector<int>> grid = {{20195,15337,73189,16963,-90840},{10664,-43796,-61984,13235,-33619}};
	int k = 2;
	Solution *test = new Solution();
	auto result = test->minAbsDiff(grid, k);
	for (const auto& r : result) {
		for (const auto& c : r) {
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}
