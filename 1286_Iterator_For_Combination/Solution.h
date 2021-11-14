#include <string>
#include <vector>
using std::vector;
using std::string;

class CombinationIterator {
    public :
	void dfs(const string& chars, int idx, string& local, int comLen) {
		if (local.size() == comLen) {
			_combination.emplace_back(local);
			return;
		}
		if (idx >= chars.size()) return;

		for (int i = idx ; i < chars.size() ; ++i) {
			local.push_back(chars[i]);
			dfs(chars, i + 1, local, comLen);
			local.pop_back();
		}
	}

	CombinationIterator(string characters, int combinationLength) {
		cIdx = 0;
		string local;
		dfs(characters, 0, local, combinationLength);
	}

	string next() {
		if (cIdx < _combination.size()) {
			return _combination[cIdx++];
		} else {
			return "";
		}
	}

	bool hasNext() {
		return cIdx < _combination.size();
	}
    private :
	vector<string> _combination;
	int cIdx;
        virtual ~CombinationIterator() {}
        CombinationIterator& operator=(const CombinationIterator& source);
        CombinationIterator(const CombinationIterator&);
};

