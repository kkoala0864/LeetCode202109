#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0, 100}};
	vector<int> remove = {50,100};
	Solution *test = new Solution();
	auto result = test->removeInterval(input, remove);
	for (const auto &v : result) {
		cout << "[" << v[0] << " : " << v[1] << "]" << endl;
	}
	return 0;
}
