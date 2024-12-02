#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::isPrefixOfWord(string sentence, string searchWord) {
	int ss = searchWord.size();
	int si = 1;
	string tmp;

	for (int i = 0 ; i < sentence.size() ; ++i) {
		if (sentence[i] == ' ') {
			if (tmp.size() >= ss) {
				int j = 0;
				for (; j < ss ; ++j) {
					if (tmp[j] != searchWord[j]) break;
				}
				if (j == ss) return si;
			}
			tmp.clear();
			++si;
		} else {
			tmp.push_back(sentence[i]);
		}
	}
	if (tmp.size() >= ss) {
		int j = 0;
		for (; j < ss ; ++j) {
			if (tmp[j] != searchWord[j]) break;
		}
		if (j == ss) return si;
	}
	return -1;
}
