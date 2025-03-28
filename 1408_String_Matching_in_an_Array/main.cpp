#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"mass", "as", "hero", "superhero"};
	Solution *test = new Solution();
	auto result = test->stringMatching(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
