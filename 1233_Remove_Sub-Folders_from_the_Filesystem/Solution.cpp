#include <Solution.h>

vector<string> Solution::removeSubfolders(vector<string> &folder) {
	auto cmp = [](const string& lhs, const string& rhs) {
		return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
	};

	sort(folder.begin(), folder.end(), cmp);

	vector<string> result;
	Trie* root = new Trie();

	for (auto& f : folder) {
		f.push_back('/');
		auto iter = root;
		bool hasPrefix = false;
		for (const auto& c : f) {
			int idx = c == '/' ? 26 : c - 'a';
			if (!iter->children[idx]) iter->children[idx] = new Trie();
			iter = iter->children[idx];
			if (iter->isEnd) {
				hasPrefix = true;
				break;
			}
		}
		if (!hasPrefix) {
			iter->isEnd = true;
			f.pop_back();
			result.emplace_back(f);
		}
	}
	return result;
}
