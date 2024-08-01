#include <data_type.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::to_string;

class ValidWordAbbr {
    public :
	    ValidWordAbbr() {}
	    string getAbbr(const string& word) {
		if (word.size() < 3) return word;
		string abbr(1, word[0]);
		int v = word.size() - 2;
		abbr += to_string(v);
		abbr.push_back(word.back());
		return abbr;
	    }

	    ValidWordAbbr(vector<string>& dictionary) {
		    for (const auto& d : dictionary) {
			    string abbr = getAbbr(d);
			    m[abbr].emplace(d);
		    }
	    }

	    bool isUnique(string word) {
		    string abbr = getAbbr(word);
		    if (m.count(abbr) == 0) return true;
		    if (m[abbr].size() > 1) return false;
		    return m[abbr].count(word);
	    }
    private :
	    unordered_map<string, unordered_set<string>> m;
	    virtual ~ValidWordAbbr() {}
	    ValidWordAbbr& operator=(const ValidWordAbbr& source);
	    ValidWordAbbr(const ValidWordAbbr&);
};

