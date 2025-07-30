#include <Solution.h>

int main(void) {
	vector<int> input = {0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,32,2,0,0,0,0,0,0,28,16,32,0,0,0,0,0,0,0,1,0,8,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,16,0,0,0,0,2,0,0,32,0,0,0,4,16,0,4,0,32,0,0,8,0,1,1,0,0,0,0,0};
	Solution *test = new Solution();
	auto ret = test->smallestSubarrays(input);
	for (const auto& v : ret) cout << v << " ";
	cout << endl;
	return 0;
}
