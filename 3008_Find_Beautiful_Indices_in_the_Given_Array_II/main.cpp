#include <Solution.h>

int main(void) {
	string s = "abcd";
	string a = "a";
	string b = "a";
	int k = 15;
	Solution *test = new Solution();
	auto result = test->beautifulIndices(s, a, b, k);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
