#include <string>
#include <vector>

using std::string;
using std::vector;

class Trie {
public:
	Trie() {
		next = vector<Trie *>(26, nullptr);
		isEnd = false;
	}

	void insert(string word) {
		Trie *iter = this;
		for (const auto &c : word) {
			if (!iter->next[c - 'a'])
				iter->next[c - 'a'] = new Trie();
			iter = iter->next[c - 'a'];
		}
		iter->isEnd = true;
	}

	bool search(string word) {
		Trie *iter = this;
		for (const auto &c : word) {
			if (!iter->next[c - 'a'])
				return false;
			iter = iter->next[c - 'a'];
		}
		return iter->isEnd;
	}

	bool startsWith(string prefix) {
		Trie *iter = this;
		for (const auto &c : prefix) {
			if (!iter->next[c - 'a'])
				return false;
			iter = iter->next[c - 'a'];
		}
		return true;
	}

private:
	bool isEnd;
	vector<Trie *> next;
	virtual ~Trie() {
	}
	Trie &operator=(const Trie &source);
	Trie(const Trie &);
};
