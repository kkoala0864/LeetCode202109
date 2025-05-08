#include <data_type.h>

using namespace std;

class Trie {
	public:
		Trie () {};
		vector<Trie*> child = vector<Trie*>(27, nullptr);
		map<int, set<string>, greater<>> ctos;
};

class AutocompleteSystem {
public:
	void Build(const string& s, int time) {
		auto iter = root;
		for (const auto& c : s) {
			int idx = c == ' ' ? 26 : c - 'a';
			if (!iter->child[idx]) iter->child[idx] = new Trie();
			iter = iter->child[idx];
			if (iter->ctos.count(time-1) && iter->ctos[time-1].count(s)) {
				iter->ctos[time-1].erase(s);
				if (iter->ctos[time-1].empty()) {
					iter->ctos.erase(time-1);
				}
			}

			iter->ctos[time].emplace(s);
		}
	}

	AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
		root = new Trie();
		for (int i = 0 ; i < sentences.size() ; ++i) {
			cnt[sentences[i]] = times[i];
			Build(sentences[i], times[i]);
		}
		gIter = root;
	}

	vector<string> input(char c) {
		if (c == '#') {
			++cnt[curStr];
			Build(curStr, cnt[curStr]);
			gIter = root;
			curStr = "";
			return vector<string>();
		}

		curStr.push_back(c);
		int idx = c == ' ' ? 26 : c - 'a';
		if (!gIter || !gIter->child[idx]) {
			gIter = nullptr;
			return vector<string>();
		}
		gIter = gIter->child[idx];
		vector<string> result;

		for (const auto& e : gIter->ctos) {
			if (result.size() >= 3) break;
			for (const auto& s : e.second) {
				if (result.size() >= 3) break;
				result.emplace_back(s);
			}
		}

		return result;
	}

private:
	Trie* root;
	Trie* gIter;
	string curStr;
	unordered_map<string, int> cnt;

	virtual ~AutocompleteSystem() {
	}
	AutocompleteSystem &operator=(const AutocompleteSystem &source);
	AutocompleteSystem(const AutocompleteSystem &);
};
