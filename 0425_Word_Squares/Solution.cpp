#include <Solution.h>

void dfs(int curIdx, int size, vector<string>& cur, Trie* root, vector<vector<string>>& result) {
	if (curIdx == size) {
		result.emplace_back(cur);
		return;
	}

	auto iter = root;
	for (int i = 0 ; i < curIdx ; ++i) {
		if (!iter->children[cur[i][curIdx]-'a']) return;
		iter = iter->children[cur[i][curIdx]-'a'];
	}
	for (const auto n : iter->preStr) {
		cur.emplace_back(n);
		dfs(curIdx + 1, size, cur, root, result);
		cur.pop_back();
	}
}

vector<vector<string>> Solution::wordSquares(vector<string>& words) {
	Trie* root = new Trie();
	for (const auto& w : words) {
		auto iter = root;
		for (const auto& c : w) {
			if (!iter->children[c-'a']) iter->children[c-'a'] = new Trie();
			iter = iter->children[c-'a'];;
			iter->preStr.emplace_back(w);
		}
	}

	vector<vector<string>> result;
	for (const auto& w : words) {
		vector<string> cur(1, w);
		dfs(1, w.size(), cur, root, result);
	}
	return result;
}
