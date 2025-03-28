#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"Mary", "John", "Emma"};
	vector<int> heights = {180, 165, 170};
	Solution *test = new Solution();
	auto result = test->sortPeople(input, heights);
	for (const auto &s : result)
		cout << s << " ";
	cout << endl;
	return 0;
}
