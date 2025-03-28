#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class WordDictionary {
public:
	bool isEnd;
	vector<WordDictionary *> next;
	WordDictionary() {
		isEnd = false;
		next = vector<WordDictionary *>(26, nullptr);
	}

	void addWord(string word) {
		WordDictionary *node = this;
		for (const auto &iter : word) {
			if (node->next[iter - 'a'] == nullptr) {
				node->next[iter - 'a'] = new WordDictionary();
			}
			node = node->next[iter - 'a'];
		}
		node->isEnd = true;
	}

	bool WildcardSeach(WordDictionary *node, const string &word, int index) {
		for (int i = index; i < word.size(); ++i) {
			if (word[i] == '.') {
				for (const auto &iter : node->next) {
					if (iter) {
						if (WildcardSeach(iter, word, i + 1))
							return true;
					}
				}
				return false;
			} else {
				if (node->next[word[i] - 'a']) {
					node = node->next[word[i] - 'a'];
				} else {
					return false;
				}
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
