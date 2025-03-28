#include <string>
#include <vector>

using std::string;
using std::vector;

class Trie {
public:
	bool isEnd;
	vector<Trie *> next;
	Trie() {
		next = vector<Trie *>(26, nullptr);
		isEnd = false;
	}

	void insert(string word) {
		Trie *iter = this;
		for (const auto &ch : word) {
			if (!iter->next[ch - 'a']) {
				iter->next[ch - 'a'] = new Trie();
			}
			iter = iter->next[ch - 'a'];
		}
		iter->isEnd = true;
	}

	bool search(string word) {
		Trie *iter = this;
		for (const auto &ch : word) {
			if (!iter->next[ch - 'a'])
				return false;
			iter = iter->next[ch - 'a'];
		}
		return iter->isEnd;
	}

	bool startsWith(string prefix) {
		Trie *iter = this;
		for (const auto &ch : prefix) {
			if (!iter->next[ch - 'a'])
				return false;
			iter = iter->next[ch - 'a'];
		}
		return true;
	}

private:
	virtual ~Trie() {
	}
	Trie &operator=(const Trie &source);
	Trie(const Trie &);
};
