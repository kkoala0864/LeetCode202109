#include <data_type.h>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::to_string;

class Excel {
	public :
		Excel(int height, char width) {
			int w = (width - 'A') + 1;
			data = vector<vector<int>>(height + 1, vector<int>(w, 0));
			dep = vector<vector<vector<string>>>(height + 1, vector<vector<string>>(w, vector<string>()));
		}

		void set(int row, char column, int val) {
			string idx = column + to_string(row);
			int c = column - 'A';
			dep[row][c].clear();
			data[row][c] = val;
		}

		int dfs(const string& idx) {
			int commaIdx = idx.find(":");
			bool comma = commaIdx != std::string::npos;
			int sc = idx[0] - 'A';
			int sr = comma ? stoi(idx.substr(1, commaIdx - 1)) : stoi(idx.substr(1));
			int tc = comma ? idx[commaIdx + 1] - 'A': sc;
			int tr = comma ? stoi(idx.substr(commaIdx + 2)) : sr;

			int result = 0;
			if (!comma) {
				if (dep[sr][sc].empty()) {
					return data[sr][sc];
				} else {
					for (const auto& subIdx : dep[sr][sc]) {
						result += dfs(subIdx);
					}
				}
			} else {
				for (int i = sr ; i <= tr ; ++i) {
					for (int j = sc ; j <= tc ; ++j) {
						string subIdx = string(1, j + 'A') + to_string(i);
						result += dfs(subIdx);
					}
				}
			}
			return result;
		}
		int get(int row, char column) {
			string idx = column + to_string(row);
			return dfs(idx);
		}

		int sum(int row, char column, vector<string> numbers) {
			int c = column - 'A';
			dep[row][c] = numbers;
			string idx = column + to_string(row);
			return dfs(idx);
		}
	private :
		vector<vector<int>> data;
		vector<vector<vector<string>>> dep;
    private :
        virtual ~Excel() {}
        Excel& operator=(const Excel& source);
        Excel(const Excel&);
};

