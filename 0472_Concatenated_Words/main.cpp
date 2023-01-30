#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
	Solution* test = new Solution();
	auto result = test->findAllConcatenatedWordsInADict(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

