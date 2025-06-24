#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4,5,6,7,8,9,10};
	int key = 2;
	int k = 5;
	Solution *test = new Solution();
	auto result = test->findKDistantIndices(input, key, k);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
