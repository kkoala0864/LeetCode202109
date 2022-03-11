#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using std::unordered_map;
using std::string;
using std::vector;
using std::min;

class WordDistance {
    public :
	WordDistance(vector<string>& wordsDict) {
		for (int i = 0 ; i < wordsDict.size() ; ++i) {
			uMap[wordsDict[i]].emplace_back(i);
		}
	}

	int shortest(string word1, string word2) {
		int result = INT_MAX;
		int i1 = 0 , i2 = 0;
		while (i1 < uMap[word1].size() && i2 < uMap[word2].size()) {
			result = min(result, abs(uMap[word1][i1] - uMap[word2][i2]));
			if (uMap[word1][i1] > uMap[word2][i2]) {
				++i2;
			} else {
				++i1;
			}
		}
		return result;
	}
    private :
	unordered_map<string, vector<int>> uMap;
        virtual ~WordDistance() {}
        WordDistance& operator=(const WordDistance& source);
        WordDistance(const WordDistance&);
};

