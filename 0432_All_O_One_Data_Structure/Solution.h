#include <data_type.h>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using std::map;
using std::unordered_map;
using std::unordered_set;
using std::string;
using std::cout;
using std::endl;

class AllOne {
    public :
	    AllOne() {}

	    void inc(string key) {
		if (sToc.count(key)) {
			cTos[sToc[key]].erase(key);
		}
		++sToc[key];
		cTos[sToc[key]].emplace(key);
		for (const auto& c : cTos) {
			cout << c.first << " : ";
			for (const auto& b : c.second) {
				cout << b << " ";
			}
		}
	    }

	    void dec(string key) {
		cTos[sToc[key]].erase(key);
		--sToc[key];
		if (sToc[key] > 0) {
			cTos[sToc[key]].emplace(key);
		} else {
			sToc.erase(key);
		}
	    }

	    string getMaxKey() {
		    for (auto ri = cTos.rbegin() ; ri != cTos.rend() ; ++ri) {
			if (!ri->second.empty()) {
				return *(ri->second.begin());
			}
		    }
		    return "";
	    }

	    string getMinKey() {
		    for (auto i = cTos.begin() ; i != cTos.end() ; ++i) {
			if (!i->second.empty()) {
				return *(i->second.begin());
			}
		    }
		    return "";
	    }
    private :
	    unordered_map<string, int> sToc;
	    map<int, unordered_set<string>> cTos;
	    virtual ~AllOne() {}
	    AllOne& operator=(const AllOne& source);
	    AllOne(const AllOne&);
};

