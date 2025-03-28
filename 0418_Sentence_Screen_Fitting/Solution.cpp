#include <Solution.h>
#include <iostream>

int Solution::wordsTyping(vector<string> &sentence, int rows, int cols) {
	string allStr("");
	for (const auto iter : sentence) {
		allStr += (iter + " ");
	}

	int loc = 0;
	for (int i = 0; i < rows; ++i) {
		loc += cols;

		if (allStr[loc % allStr.size()] == ' ') {
			++loc;
		} else {
			while (loc > 0 && allStr[(loc - 1) % allStr.size()] != ' ') {
				--loc;
			}
		}
	}
	return loc / allStr.size();
}

/*
int Solution::wordsTyping(vector<string>& sentence, int rows, int cols) {
        int cnt = 0;
        int x = 0, y = 0;
        int sIdx = 0;
        while (x < rows) {
                while (y < cols) {
                        if ((cols - y) >= sentence[sIdx].size()) {
                                y += sentence[sIdx].size();
                                ++sIdx;
                                if (sIdx == sentence.size()) {
                                        ++cnt;
                                        sIdx = 0;
                                }
                                ++y;
                        } else {
                                y = cols;
                        }
                }
                y = 0;
                ++x;
        }
        return cnt;
}*/
