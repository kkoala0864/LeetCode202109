#include <Solution.h>

int main(void) {
	string input = "{{a,z},a{b,c},{ab,z}}";
	Solution *test = new Solution();
	auto result = test->braceExpansionII(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
