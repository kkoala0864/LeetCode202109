#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,4,5},{1,4,7},{4,7,1},{4,7,11}};
	Solution *test = new Solution();
	auto result = test->splitPainting(input);

	for (const auto& iter : result) {
		for (const auto& v : iter) {
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}
