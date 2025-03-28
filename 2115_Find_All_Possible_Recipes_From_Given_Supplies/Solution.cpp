#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using std::queue;
using std::unordered_map;

vector<string> Solution::findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
	unordered_map<string, vector<string>> od;
	unordered_map<string, int> idc;

	for (int i = 0; i < recipes.size(); ++i) {
		for (const auto &ing : ingredients[i]) {
			od[ing].emplace_back(recipes[i]);
			++idc[recipes[i]];
		}
	}
	queue<string> que;
	for (const auto &sup : supplies)
		que.emplace(sup);
	vector<string> result;

	while (!que.empty()) {
		string cur = que.front();
		que.pop();
		for (const auto &r : od[cur]) {
			--idc[r];
			if (idc[r] == 0) {
				result.emplace_back(r);
				que.emplace(r);
			}
		}
	}
	return result;
}
