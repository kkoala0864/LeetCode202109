#include <Solution.h>

int main(void) {
	vector<vector<int>> matrix = {{20,-21,14},{-19,4,19},{22,-47,24},{-19,4,19}};
	Solution *test = new Solution();
	auto result = test->matrixRankTransform(matrix);
	for (const auto& r : result) {
		for (const auto& c : r) {
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}
