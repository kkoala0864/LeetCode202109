#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> reciepts = {"bread"};
	vector<vector<string>> ingredients = {{"yeast","flour"}};
	vector<string> supplies = {"yeast","flour","corn"};
	Solution* test = new Solution();
	auto result = test->findAllRecipes(reciepts, ingredients, supplies);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

