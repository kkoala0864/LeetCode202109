#include <Solution.h>

int main(void) {
	vector<string> queries = {"word","note","ants","wood"};
	vector<string> dictionary = {"wood","joke","moat"};
	Solution *test = new Solution();
	auto result = test->twoEditWords(queries, dictionary);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
