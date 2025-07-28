#include <Solution.h>

vector<int> getSPF(int mx) {
	vector<int> spf(mx + 1, 0);
	for (int i = 1 ; i <= mx ; ++i) spf[i] = i;

	for (int i = 2 ; i <= mx ; ++i) {
		if (spf[i] != i) continue;
		for (int j = i ; j <= mx/i ; ++j) {
			if (spf[i * j] != i * j) continue;
			spf[i * j] = i;
		}
	}
	return spf;
}

vector<int> getPF(int v, vector<int>& spf) {
	vector<int> ret;
	while (v > 1) {
		int p = spf[v];
		ret.emplace_back(p);
		while (v % p == 0) v /= p;
	}
	return ret;
}

int Solution::minJumps(vector<int>& nums) {
	int size = nums.size();
	int mx = 0;
	for (const auto& v : nums) mx = max(mx, v);

	auto spf = getSPF(mx);
	unordered_map<int, vector<int>> pI;
	vector<vector<int>> adj(size, vector<int>());

	for (int i = 0 ; i < size ; ++i) {
		auto pf = getPF(nums[i], spf);
		for (const auto& v : pf) {
			if (pI.count(v) == 0) continue;
			for (const auto& idx : pI[v]) {
				adj[idx].emplace_back(i);
				adj[i].emplace_back(idx);
			}
		}
		if (spf[nums[i]] == nums[i]) {
			pI[nums[i]].emplace_back(i);
		}
	}

	vector<int> dist(size, -1);
	queue<int> que;
	dist[0] = 0;
	que.emplace(0);

	while (!que.empty()) {
		int idx = que.front();
		que.pop();

		int step = dist[idx];

		if (idx == size - 1) return step;
		if (idx - 1 >= 0 && dist[idx-1] == -1) {
			dist[idx-1] = step + 1;
			que.emplace(idx-1);
		}
		if (idx + 1 < size && dist[idx+1] == -1) {
			dist[idx+1] = step + 1;
			que.emplace(idx+1);
		}
		if (spf[nums[idx]] == nums[idx]) {
			for (const auto& nIdx : adj[idx]) {
				if (dist[nIdx] != -1) continue;
				dist[nIdx] = step + 1;
				que.emplace(nIdx);
			}
			adj[idx].clear();
		}
	}
	return -1;
}
