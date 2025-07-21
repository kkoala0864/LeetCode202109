#include <Solution.h>

string getSig(Trie* node, unordered_map<string, int>& freq) {
	if (node->ch.empty()) return "";
	vector<pair<string, string>> subs(node->ch.size(), pair<string, string>());
	for (const auto& [name, child] : node->ch) {
		subs.emplace_back(pair<string, string>(name, getSig(child, freq)));
	}
	sort(subs.begin(), subs.end());

	string sig = "(";
	for (const auto& [n, s] :subs) sig += (n + s);
	sig += ")";
	++freq[sig];
	return sig;
}

string mark(Trie* node, unordered_map<string, int>& freq) {
	if (node->ch.empty()) return "";
	vector<pair<string, string>> subs(node->ch.size(), pair<string, string>());

	for (const auto& [name, child] : node->ch) {
		subs.emplace_back(pair<string, string>(name, mark(child, freq)));
	}
	sort(subs.begin(), subs.end());

	string sig = "(";
	for (const auto& [n, s] : subs) sig += (n + s);
	sig += ")";
	if (freq[sig] > 1) node->deleted = true;
	return sig;
}

void collect(Trie* node, Trie* root, vector<string>& cur, vector<vector<string>>& result) {
	if (node != root) {
		if (node->deleted) return;
		result.emplace_back(cur);
	}

	for (const auto& [name, child] : node->ch) {
		cur.emplace_back(name);
		collect(child, root, cur, result);
		cur.pop_back();
	}
}

vector<vector<string>> Solution::deleteDuplicateFolder(vector<vector<string>>& paths) {
	Trie* root = new Trie();
	unordered_map<string, int> freq;

	for (const auto& p : paths) {
		auto iter = root;
		for (const auto& s : p) {
			if (!iter->ch[s]) iter->ch[s] = new Trie();
			iter = iter->ch[s];
		}
	}

	vector<vector<string>> result;
	vector<string> cur;
	getSig(root, freq);
	mark(root, freq);
	collect(root, root, cur, result);
	return result;
}
