#include <Solution.h>
#include <iostream>
#include <set>
#include <unordered_map>

using std::set;
using std::unordered_map;

void find(string &idx, unordered_map<string, string> &map) {
	while (idx != map[idx])
		idx = map[idx];
}

vector<vector<string>> Solution::accountsMerge(vector<vector<string>> &accounts) {
	unordered_map<string, unordered_map<string, string>> graph;
	for (const auto &account : accounts) {
		string name = account[0];
		string root = account[1];

		if (graph[name].find(root) == graph[name].end())
			graph[name][root] = root;
		else
			find(root, graph[name]);

		for (int i = 2; i < account.size(); ++i) {
			string node = account[i];
			if (graph[name].find(node) == graph[name].end())
				graph[name][node] = root;
			else {
				find(node, graph[name]);
				graph[name][node] = root;
			}
		}
	}

	unordered_map<string, unordered_map<string, set<string>>> uMap;
	for (auto &people : graph) {
		string name = people.first;
		for (auto &iter : people.second) {
			string root = iter.first;
			find(root, people.second);
			uMap[name][root].emplace(iter.first);
		}
	}

	vector<vector<string>> result;
	for (const auto &ele : uMap) {
		string name = ele.first;
		for (const auto &mail : ele.second) {
			vector<string> insert;
			insert.emplace_back(name);
			for (const auto &m : mail.second)
				insert.emplace_back(m);
			result.emplace_back(insert);
		}
	}

	return result;
}
