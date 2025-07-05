#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3,4,5};
	int k = 2;
	Solution *test = new Solution();
	auto result = test->getStrongest(input, k);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
