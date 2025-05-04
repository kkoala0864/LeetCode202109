#include <Solution.h>

int main(void) {
	int N = 2;
	Solution *test = new Solution();
	auto result = test->specialGrid(N);

	for (const auto& row : result) {
		for (const auto& cell : row) {
			std::cout << cell << " ";
		}
		cout << endl;
	}
	return 0;
}
