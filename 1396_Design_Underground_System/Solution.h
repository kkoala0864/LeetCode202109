#include <string>
#include <unordered_map>

using std::pair;
using std::string;
using std::unordered_map;

class UndergroundSystem {
public:
	UndergroundSystem() {
	}

	void checkIn(int id, string stationName, int t) {
		_inRecord[id] = pair<string, int>(stationName, t);
	}

	void checkOut(int id, string stationName, int t) {
		int timeDiff = t - _inRecord[id].second;
		if (_timeSlice.find(_inRecord[id].first) == _timeSlice.end()
		    || _timeSlice[_inRecord[id].first].find(stationName) == _timeSlice[_inRecord[id].first].end()) {
			_timeSlice[_inRecord[id].first][stationName] = pair<int, int>(timeDiff, 1);
		} else {
			_timeSlice[_inRecord[id].first][stationName].first += timeDiff;
			++_timeSlice[_inRecord[id].first][stationName].second;
		}
	}

	double getAverageTime(string startStation, string endStation) {
		return _timeSlice[startStation][endStation].first / _timeSlice[startStation][endStation].second;
	}

private:
	unordered_map<int, pair<string, int>> _inRecord;
	unordered_map<string, unordered_map<string, pair<double, double>>> _timeSlice;
	virtual ~UndergroundSystem() {
	}
	UndergroundSystem &operator=(const UndergroundSystem &source);
	UndergroundSystem(const UndergroundSystem &);
};
