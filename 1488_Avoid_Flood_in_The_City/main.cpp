#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,0,0,2,1};
	Solution *test = new Solution();
	auto result = test->avoidFlood(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
