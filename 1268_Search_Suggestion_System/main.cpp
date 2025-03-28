#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"havana"};
	string searchWord = "tatiana";
	Solution *test = new Solution();
	auto result = test->suggestedProducts(input, searchWord);
	for (const auto &words : result) {
		for (const auto &w : words) {
			cout << w << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
