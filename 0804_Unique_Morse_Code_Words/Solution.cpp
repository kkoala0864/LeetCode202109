#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

int Solution::uniqueMorseRepresentations(vector<string>& words) {
	vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

	unordered_set<string> uSet;
	int result = 0;
	for (const auto& w : words) {
		string local;
		for (const auto& v : w) {
			local += code[v-'a'];
		}
		if (uSet.find(local) == uSet.end()) {
			++result;
			uSet.emplace(local);
		}
	}
	return result;
}
