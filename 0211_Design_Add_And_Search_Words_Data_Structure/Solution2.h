#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class WordDictionary {
public:
	bool isEnd;
	vector<WordDictionary *> next;
	WordDictionary() {
		next = vector<WordDictionary *>(26, nullptr);
		isEnd = false;
	}

	void addWord(string word) {
		WordDictionary *iter = this;
		for (const auto &ch : word) {
			if (!iter->next[ch - 'a'])
				iter->next[ch - 'a'] = new WordDictionary();
			iter = iter->next[ch - 'a'];
		}
		iter->isEnd = true;
	}

	bool WildcardSeach(WordDictionary *node, const string &word, int index) {
		for (int i = index; i < word.size(); ++i) {
			if (word[i] == '.') {
				for (const auto &iter : node->next) {
					if (iter)
						if (WildcardSeach(iter, word, i + 1))
							return true;
				}
				return false;
			} else {
				if (node->next[word[i] - 'a'])
					node = node->next[word[i] - 'a'];
				else
					return false;
			}
		}
		return node->isEnd;
	}

	bool search(string word) {
		return WildcardSeach(this, word, 0);
	}

private:
	virtual ~WordDictionary() {
	}
	WordDictionary &operator=(const WordDictionary &source);
	WordDictionary(const WordDictionary &);
};
