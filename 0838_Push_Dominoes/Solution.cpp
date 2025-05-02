#include <Solution.h>
#include <stack>

string Solution::pushDominoes(string dominoes) {
	stack<int> st;

	st.emplace(-1);
	for (int i = 0 ; i < dominoes.size() ; ++i) {
		if (dominoes[i] == 'R') {
			while (!st.empty()) {
				st.pop();
			}
			st.emplace(i);
		} else if (dominoes[i] == 'L') {
			if (!st.empty()) {
				if (st.top() == -1 || dominoes[st.top()] == 'L') {
					for (int j = st.top() + 1 ; j < i ; ++j) {
						dominoes[j] = 'L';
					}
				} else {
					int offset = (i - st.top() - 1);
					for (int j = 1 ; j <= (offset / 2) ; ++j) {
						dominoes[i - j] = 'L';
					}
					if (offset & 1) {
						dominoes[i - (offset / 2) - 1] = '.';
					}
				}
				st.pop();
			}
			st.emplace(i);
		} else {
			if (!st.empty() && st.top() != -1 && dominoes[st.top()] == 'R') {
				dominoes[i] = 'R';
			}
		}
	}
	return dominoes;
}
