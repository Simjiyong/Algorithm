#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const int MAX_N = 200000;
vector<int> adj[MAX_N];
int p[MAX_N], s[MAX_N];
bool visit[MAX_N];
bool answer;
int cnt;
void dfs(int here, int n) {
	int next;
	for (int i = 0; i < adj[here].size(); i++) {
		next = adj[here][i];
		if (visit[next])
			continue;
		if (!visit[p[next]]) {
			s[p[next]] = next;
			continue;
		}
		visit[next] = true;
		cnt++;
		dfs(next, n);
	}
	if (s[here] != 0) {
		visit[s[here]] = true;
		dfs(s[here], n);
	}
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	answer = false;
	int a, b;
	for (int i = 0; i < path.size(); i++) {
		a = path[i][0];
		b = path[i][1];
		adj[b].push_back(a);
		adj[a].push_back(b);
	}
	int from, to;
	for (int i = 0; i < order.size(); i++) {
		from = order[i][0];
		to = order[i][1];
		if (to == 0)
			return false;
		p[to] = from;
	}
	cnt = 1;
	visit[0] = true;
	dfs(0, n);
	for (int i = 0; i < n; i++) {
		if (!visit[i])
			return false;
	}
	return true;
}