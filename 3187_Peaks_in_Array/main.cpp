#include <Solution.h>

int main(void) {
	vector<int> input = {4,1,4,2,1,5};
	vector<vector<int>> query = {{2,2,4},{1,0,2},{1,0,4}};
	Solution *test = new Solution();
	auto result = test->countOfPeaks(input, query);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
