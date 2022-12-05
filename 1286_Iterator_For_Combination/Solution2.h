#include <string>
#include <vector>

using std::vector;
using std::string;

class CombinationIterator {
    public :
	CombinationIterator(string characters, int combinationLength) {
		s = characters;
		csize = combinationLength;
		for (int i = 0 ; i < csize ; ++i) idx.emplace_back(i);
	}

	string next() {
		string result;
		for (const auto& c : idx) result.push_back(s[c]);
		int carry = 1;
		int i = idx.size() - 1;
		while (i >= 0) {
			idx[i] += carry;
			if (idx[i] > (s.size() - (csize - i))) {
				carry = 1;
				--i;
			} else {
				break;
			}
		}
		if (idx[0] <= (s.size() - csize)) {
			for (int j = i + 1 ; j < idx.size() ; ++j) {
				idx[j] = idx[j-1] + 1;
			}
		}
		return result;
	}
	bool hasNext() {
		return idx[0] <= (s.size() - csize);
	}
    private :
	string s;
	int csize;
	vector<int> idx;
        virtual ~CombinationIterator() {}
        CombinationIterator& operator=(const CombinationIterator& source);
        CombinationIterator(const CombinationIterator&);
};

