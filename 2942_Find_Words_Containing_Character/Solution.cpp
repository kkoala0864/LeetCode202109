#include <Solution.h>

vector<int> Solution::findWordsContaining(vector<string>& words, char x) {
	vector<int> result;
	for (int i = 0 ; i < words.size() ; ++i) {
		if (words[i].find(x) != string::npos) {
			result.emplace_back(i);
		}
	}
	return result;

}
