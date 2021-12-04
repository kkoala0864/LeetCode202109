#include <string>
#include <vector>

using std::string;
using std::vector;

class TrieNode {
	public:
		vector<TrieNode*> next;
		bool isEnd;
		TrieNode() : isEnd(false) {
			next = vector<TrieNode*>(26, nullptr);
		}
};

class StreamChecker {
    public :
	StreamChecker(vector<string>& words) {
		root = new TrieNode();
		for (auto& word : words) {
			BuildTrie(word);
		}
		s = "";
	}

	bool query(char letter) {
		s += letter;
		return search(s);
	}
    private :
	TrieNode* root;
	string s;
	void BuildTrie(string& word) {
		TrieNode* iter = root;
		for (int i = word.size() - 1 ; i >= 0 ; --i) {
			if (iter->next[word[i]-'a'] == nullptr) {
				iter->next[word[i]-'a'] = new TrieNode();
			}
			iter = iter->next[word[i]-'a'];
		}
		iter->isEnd = true;
	}
	bool search(string& word) {
		TrieNode* iter = root;
		for (int i = word.size() - 1 ; i >= 0 ; --i) {
			if (iter->next[word[i]-'a']) {
				iter = iter->next[word[i]-'a'];
				if (iter->isEnd) return true;
			} else {
				return false;
			}
		}
		return false;
	}

        virtual ~StreamChecker() {}
        StreamChecker& operator=(const StreamChecker& source);
        StreamChecker(const StreamChecker&);
};

