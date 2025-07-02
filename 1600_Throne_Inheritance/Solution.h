#include <data_type.h>

class ThroneInheritance {
public:
	ThroneInheritance(string kingName) {
		root = kingName;
	}

	void birth(string parentName, string childName) {
		child[parentName].emplace_back(childName);
	}

	void death(string name) {
		dl.emplace(name);
	}

	void dfs(string cur, unordered_map<string, vector<string>>& child, const unordered_set<string>& dl, vector<string>& result) {
		if (dl.count(cur) == 0) {
			result.emplace_back(cur);
		}
		for (const auto& c : child[cur]) {
			dfs(c, child, dl, result);
		}
	}
	vector<string> getInheritanceOrder() {
		vector<string> result;
		dfs(root, child, dl, result);
		return result;
	}

private:
	unordered_map<string, vector<string>> child;
	unordered_set<string> dl;
	string root;
	virtual ~ThroneInheritance() {
	}
	ThroneInheritance &operator=(const ThroneInheritance &source);
	ThroneInheritance(const ThroneInheritance &);
};
