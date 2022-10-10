#include <Solution.h>
#include <iostream>

// string size ?
// what kind of character would exist in this input string ?
// is this input string palindrome ?


// i just need to check first half part of input string ( because input is palinedrome )
// find fist bigger char than a to reduce to a
// if input string is all a then replace last one is b
// reduce from first part string, increase from last part string
// time complexity is O(n)
// spatial complexity is O(1)

// abba -> aaba
// abcba -> aacba
// aaaaa -> aaaab
// cbaabc -> abaabc
// aba -> aaa

string Solution::breakPalindrome(string palindrome) {
	if (palindrome.size() <= 1) return "";
	int halfSize = palindrome.size() / 2;

	for (int i = 0 ; i < halfSize ; ++i) {
		if (palindrome[i] > 'a') {
			palindrome[i] = 'a';
			return palindrome;
		}
	}

	palindrome[palindrome.size()-1] = 'b';
	return palindrome;
}
