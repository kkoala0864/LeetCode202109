#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::endl;

class Solution {
    public :
        Solution() {}
	// Encodes a list of strings to a single string.
	string encode(vector<string>& strs) {
		string result = "";
		for (const auto& iter : strs) {
			int size = iter.size();
			result += to_string(size) + "@" + iter;
		}
		return result;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> result;
		int head = 0;
		while (head < s.size()) {
			int pos = s.find_first_of('@', head);
			string lenStr = s.substr(head, pos-head);
			int len = stoi(lenStr);
			head = pos + 1;
			string word = s.substr(head, len);
			result.emplace_back(word);
			head += len;
		}
		return result;
	}
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

