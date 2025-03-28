#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class WordDictionary {
public:
	vector<WordDictionary *> next;
	bool isEnd;
	WordDictionary() {
		next = vector<WordDictionary *>(26, nullptr);
		isEnd = false;
	}

	void addWord(string word) {
		WordDictionary *node = this;
		for (const auto &iter : word) {
			if (!node->next[iter - 'a'])
				node->next[iter - 'a'] = new WordDictionary();
			node = node->next[iter - 'a'];
		}
		node->isEnd = true;
	}

	bool WildcardSearch(const string &word, int idx, WordDictionary *node) {
		if (idx == word.size())
			return node->isEnd;
		if (word[idx] == '.') {
			for (const auto &iter : node->next) {
				if (iter) {
					if (WildcardSearch(word, idx + 1, iter))
						return true;
				}
			}
			return false;
		}
		if (!node->next[word[idx] - 'a'])
			return false;
		return WildcardSearch(word, idx + 1, node->next[word[idx] - 'a']);
	}

	bool search(string word) {
		return WildcardSearch(word, 0, this);
	}

private:
	virtual ~WordDictionary() {
	}
	WordDictionary &operator=(const WordDictionary &source);
	WordDictionary(const WordDictionary &);
};
