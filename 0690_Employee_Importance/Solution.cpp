#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int dfs(unordered_map<int, Employee*>& m, int id) {
	int ret = 0;

	ret += m[id]->importance;
	for (const auto& v : m[id]->subordinates) {
		ret += dfs(m, v);
	}
	return ret;
}

int Solution::getImportance(vector<Employee*> employees, int id) {
	unordered_map<int, Employee*> m;
	for (const auto& e : employees) {
		m[e->id] = e;
	}
	return dfs(m, id);
}
