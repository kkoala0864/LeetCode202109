#include <data_type.h>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;

struct Trie
{
	Trie()
	    : isEnd(false) {
		child = vector<Trie *>(27, nullptr);
	}

	vector<Trie *> child;
	bool isEnd;
};

class Solution {
public:
	Solution() {
	}
	vector<string> removeSubfolders(vector<string> &folder);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
