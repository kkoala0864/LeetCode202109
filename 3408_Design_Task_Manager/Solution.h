#include <data_type.h>
#include <queue>
#include <unordered_map>

using std::pair;
using std::priority_queue;
using std::unordered_map;

class TaskManager {
public:
	TaskManager(vector<vector<int>> &tasks) {
		for (const auto &t : tasks) {
			pq.emplace(vector<int>({t[2], t[1], t[0]}));
			pm[t[1]] = pair<int, int>(t[0], t[2]);
		}
	}

	void add(int userId, int taskId, int priority) {
		pm[taskId] = pair<int, int>(userId, priority);
		pq.emplace(vector<int>({priority, taskId, userId}));
	}

	void edit(int taskId, int newPriority) {
		pm[taskId].second = newPriority;
		pq.emplace(vector<int>({newPriority, taskId, pm[taskId].first}));
	}

	void rmv(int taskId) {
		pm.erase(taskId);
	}

	int execTop() {
		while (!pq.empty()) {
			int priority = pq.top()[0];
			int taskId = pq.top()[1];
			int userId = pq.top()[2];
			pq.pop();
			if (pm.count(taskId) == 0)
				continue;
			if (pm[taskId].second != priority)
				continue;
			int ret = pm[taskId].first;
			pm.erase(taskId);
			return ret;
		}
		return -1;
	}

private:
	priority_queue<vector<int>> pq;
	unordered_map<int, pair<int, int>> pm;
	virtual ~TaskManager() {
	}
	TaskManager &operator=(const TaskManager &source);
	TaskManager(const TaskManager &);
};
