#include <data_type.h>

class TaskManager {
public:
	TaskManager(vector<vector<int>>& tasks) {
		for (const auto& t : tasks) {
			tp[t[2]].emplace(t[1]);
			tu[t[1]] = pair<int, int>(t[0], t[2]);
		}
	}

	void add(int userId, int taskId, int priority) {
		tp[priority].emplace(taskId);
		tu[taskId] = pair<int, int>(userId, priority);
	}

	void edit(int taskId, int newPriority) {
		int op = tu[taskId].second;
		tu[taskId].second = newPriority;
		tp[op].erase(taskId);
		if (tp[op].empty()) tp.erase(op);
		tp[newPriority].emplace(taskId);
	}

	void rmv(int taskId) {
		int op = tu[taskId].second;
		tp[op].erase(taskId);
		if (tp[op].empty()) tp.erase(op);
		tu.erase(taskId);
	}

	int execTop() {
		if (tp.empty()) return -1;
		int p = tp.begin()->first;
		int taskId = *(tp.begin()->second.begin());
		int uid = tu[taskId].first;

		tp.begin()->second.erase(taskId);
		if (tp.begin()->second.empty()) tp.erase(p);
		tu.erase(taskId);
		return uid;
	}

private:
	map<int, set<int, greater<>>, greater<>> tp;
	unordered_map<int, pair<int, int>> tu;

	virtual ~TaskManager() {
	}
	TaskManager &operator=(const TaskManager &source);
	TaskManager(const TaskManager &);
};
