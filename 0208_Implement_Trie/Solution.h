#include <string>
#include <vector>

using std::string;
using std::vector;

class Trie {
    public :
	bool isEnd;
        vector<Trie*> next;
	Trie() {
		next = vector<Trie*>(26, nullptr);
		isEnd = false;
	}

	void insert(string word) {
		Trie* node = this;
		for (const auto& iter : word) {
			if (!node->next[iter-'a']) {
				node->next[iter-'a'] = new Trie();
			}
			node = node->next[iter-'a'];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie* node = this;
		for (const auto& iter : word) {
			if (node->next[iter-'a']) node = node->next[iter-'a'];
			else return false;
		}
		if (node && node->isEnd) return true;
		else return false;
	}

	bool startsWith(string prefix) {
		Trie* node = this;
		for (const auto& iter : prefix) {
			if (node->next[iter-'a']) node = node->next[iter-'a'];
			else return false;
		}
		return node ? true : false | node->isEnd;
	}
    private :
        virtual ~Trie() {}
        Trie& operator=(const Trie& source);
        Trie(const Trie&);
};

