#include <Solution.h>
#include <iostream>

int Solution::romanToInt(string s) {
	int result = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		switch(s[i]) {
			case 'I' :
				if (i + 1 < s.size() && (s[i+1] == 'V' || s[i+1] == 'X')) {
					++i;
					if (s[i] == 'V') result += 4;
					else if (s[i] == 'X') result += 9;
				} else result += 1;
				break;
			case 'V' :
				result += 5;
				break;
			case 'X' :
				if (i + 1 < s.size() && (s[i+1] == 'L' || s[i+1] == 'C')) {
					++i;
					if (s[i] == 'L') result += 40;
					else if (s[i] == 'C') result += 90;
				} else result += 10;
				break;
			case 'L' : result += 50;
				   break;
			case 'C' :
				if (i + 1 < s.size() && (s[i+1] == 'D' || s[i+1] == 'M')) {
					++i;
					if (s[i] == 'D') result += 400;
					else if (s[i] == 'M') result += 900;
				} else result += 100;
				break;
			case 'D' : result += 500;
				   break;
			case 'M' : result += 1000;
				   break;
			default:
				break;
		}
	}
	return result;
}

