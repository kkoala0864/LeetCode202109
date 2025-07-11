#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{3,4},{5,4},{6,3},{9,1}};
	Solution *test = new Solution();
	auto result = test->getCollisionTimes(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
