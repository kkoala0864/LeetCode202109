#include <Solution.h>

int main(void) {
	vector<int> input = {1,0,2,1,3};
	Solution *test = new Solution();
	auto ret = test->smallestSubarrays(input);
	for (const auto& v : ret) cout << v << " ";
	cout << endl;
	return 0;
}
