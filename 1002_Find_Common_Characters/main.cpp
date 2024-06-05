#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"bella","label","roller"};
	Solution* test = new Solution();
	auto result = test->commonChars(input);
	for (const auto& s : result) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}

