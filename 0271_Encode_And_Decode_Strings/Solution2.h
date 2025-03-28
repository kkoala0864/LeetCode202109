#include <string>
#include <vector>
#include <iostream>

using std::stoi;
using std::string;
using std::to_string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	// Encodes a list of strings to a single string.
	string encode(vector<string> &strs) {
		string result("");
		for (const auto &str : strs) {
			int size = str.size();
			result += to_string(size) + "@" + str;
		}
		return result;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		int i = 0;
		vector<string> result;
		while (i < s.size()) {
			int j = i;
			while (j < s.size() && s[j] != '@')
				++j;
			string sizeStr = s.substr(i, j - i);
			int size = stoi(sizeStr);
			string str = s.substr(j + 1, size);
			result.emplace_back(str);
			i = j + size + 1;
		}
		return result;
	}

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
