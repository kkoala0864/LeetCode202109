#include <Solution.h>
#include <iostream>

int Solution::numberOfSpecialChars(string word) {
	int bm = 0;
	int sm = 0;
	int result = 0;

	for (const auto &c : word) {
		if (c >= 'A' && c <= 'Z') {
			int offset = 1 << (c - 'A');
			if (offset & sm) {
				if ((offset & bm) == 0)
					++result;
			}
			bm = bm | offset;
		} else {
			int offset = 1 << (c - 'a');
			if (offset & bm) {
				if ((offset & sm) == 0)
					++result;
			}
			sm = sm | offset;
		}
	}
	return result;
}
