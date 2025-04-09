#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

int compare(const string& lhs, const string& rhs) {
	int size = lhs.size();
	int ret = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (lhs[i] == rhs[i]) ++ret;
	}
	return ret;
}

void Solution::findSecretWord(vector<string>& words, Master& master) {
	unordered_set<string> st(words.begin(), words.end());

	while (!st.empty()) {
		string first = *st.begin();
		int guessed = master.guess(first);

		for (auto it = st.begin(); it!= st.end();) {
			if(compare(*it,first) != guessed) it = st.erase(it);
			else it++;
		}
		st.erase(first);
	}
}
