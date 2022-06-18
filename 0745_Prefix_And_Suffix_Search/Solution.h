#include <vector>
#include <string>
#include <set>
#include <algorithm>

using std::set;
using std::vector;
using std::string;
using std::max;

struct TrieNode {
	set<int, std::greater<int>> idx;
	vector<TrieNode*> child;
	TrieNode () {
		child = vector<TrieNode*>(26, nullptr);
	}
};

class WordFilter {
    public :
	    WordFilter(vector<string>& words) {
		    pr = new TrieNode();
		    sr = new TrieNode();
		    TrieNode* pi = pr, *si = sr;
		    for (int i = 0 ; i < words.size() ; ++i) {
			    pi = pr;
			    si = sr;
			for (int j = 0 ; j < words[i].size() ; ++j) {
				if (!pi->child[words[i][j]-'a']) {
					pi->child[words[i][j]-'a'] = new TrieNode();
				}
				pi = pi->child[words[i][j]-'a'];
				pi->idx.emplace(i);
				int sIdx = words[i].size() - 1 - j;
				if (!si->child[words[i][sIdx]-'a']) {
					si->child[words[i][sIdx]-'a'] = new TrieNode();
				}
				si = si->child[words[i][sIdx]-'a'];
				si->idx.emplace(i);
			}
		    }
	    }

	    int f(string prefix, string suffix) {
		    TrieNode* pi = pr, *si = sr;
		   for (const auto& c : prefix) {
			if (!pi->child[c-'a']) return -1;
			pi = pi->child[c-'a'];
		   }
		   for (int i = suffix.size() - 1 ; i >= 0 ; --i) {
			if (!si->child[suffix[i]-'a']) return -1;
			si = si->child[suffix[i]-'a'];
		   }

		   for (const auto& ele : pi->idx) {
			if (si->idx.find(ele) != si->idx.end()) return ele;
		   }
		   return -1;
	    }
    private :
	TrieNode* pr, *sr;
        virtual ~WordFilter() {}
        WordFilter& operator=(const WordFilter& source);
        WordFilter(const WordFilter&);
};

