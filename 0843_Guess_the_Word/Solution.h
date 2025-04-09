#include <data_type.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Master {
	public:
		Master(const vector<string>& words, string& secret, int allows) {
			for (const auto& v : words) us.emplace(v);
			this->secret = secret;
			this->allows = allows;
			cnt = 0;
		}
		int guess(string word) {
			++cnt;
			if (cnt > allows) {
				cout << "failed" << endl;
				return -1;
			}
			if (us.count(word) == 0) return -1;
			int size = secret.size();
			int ret = 0;
			for (int i = 0 ; i < size ; ++i) {
				if (word[i] == secret[i]) ++ret;
			}
			return ret;
		}
		void printCnt() {
			cout << cnt << endl;
		}
	private:
		int allows;
		unordered_set<string> us;
		string secret;
		int cnt;
};

class Solution {
public:
	Solution() {
	}
	void findSecretWord(vector<string>& words, Master& master);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
