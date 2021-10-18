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
			if (uMap.find(wordsDict[i]) == uMap.end()) {
				uMap[wordsDict[i]] = vector<int>();
			}
			uMap[wordsDict[i]].emplace_back(i);
		}
	}

	int shortest(string word1, string word2) {
		int result = INT_MAX;
		int i = 0, j = 0;
		const auto& first = uMap[word1];
		const auto& second = uMap[word2];
		while (i < first.size() && j < second.size()) {
			result = min(result, abs(first[i] - second[j]));
			if (first[i] < second[j]) ++i;
			else ++j;
		}
		return result;
	}
    private :
	unordered_map<string, vector<int>> uMap;
        virtual ~WordDistance() {}
        WordDistance& operator=(const WordDistance& source);
        WordDistance(const WordDistance&);
};

