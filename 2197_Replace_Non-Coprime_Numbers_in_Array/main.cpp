#include <Solution.h>

int main(void) {
	vector<int> input = {287,41,49,287,899,23,23,20677,5,825};
	Solution *test = new Solution();
	auto result = test->replaceNonCoprimes(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
