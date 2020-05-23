#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 10;
const int MAX_I = 6;
const int INF = 987654321;

int N, M;

int map[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
bool visit_island[MAX_I];
int cnt;


vector<pii> island[MAX_I];
int adj[MAX_I][MAX_I];

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, 1, -1, 0 }; // urld


void bfs(int y, int x) {
	queue<pii> q;

	visit[y][x] = true;
	q.push(pii(y, x));

	int size;
	pii cur;
	int ny, nx, ey, ex;
	while (!q.empty()) {
		size = q.size();
		while (size--) {
			cur = q.front();
			q.pop();
			island[cnt].push_back(cur);

			for (int dir = 0; dir < 4; dir++) {
				ny = cur.first + dy[dir];
				nx = cur.second + dx[dir];
				if (ny < 0 || nx < 0 || ny > N - 1 || nx > M - 1)
					continue;
				if (visit[ny][nx] || !map[ny][nx])
					continue;
				visit[ny][nx] = true;
				q.push(pii(ny, nx));
			}
		}
	}
}

void get_island() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
}

int calc(int y, int x, int dir, int blank[MAX_N][MAX_N]) {

	int ny, nx, len = 0;
	ny = y, nx = x;

	while (1) {
		ny += dy[dir];
		nx += dx[dir];

		if (ny < 0 || nx < 0 || ny > N - 1 || nx > M - 1)
			return INF;
		if (!blank[ny][nx] && map[ny][nx])
			return INF;
		if (blank[ny][nx])
			break;

		len++;
	}
	if (len <= 1)
		return INF;
	return len;
}

void draw(int p, int blank[MAX_N][MAX_N]) {
	int y, x;
	for (int i = 0; i < island[p].size(); i++) {
		y = island[p][i].first;
		x = island[p][i].second;
		blank[y][x] = 1;
	}
}

int get_len(int p1, int p2) {
	int blank[MAX_N][MAX_N];
	for (int i = 0; i < MAX_N; i++) for (int j = 0; j < MAX_N; j++)
		blank[i][j] = 0;

	draw(p2, blank);

	int len = INF;
	int y, x;
	for (int i = 0; i < island[p1].size(); i++) {
		y = island[p1][i].first;
		x = island[p1][i].second;

		for (int dir = 0; dir < 4; dir++) {
			len = min(len, calc(y, x, dir, blank));
		}
	}

	return len;
}

void make_adj() {
	for (int i = 0; i < cnt - 1; i++) {
		for (int j = i + 1; j < cnt; j++) {
			adj[i][j] = adj[j][i] = get_len(i, j);
		}
	}
}

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		cin >> map[i][j];

	for (int i = 0; i < MAX_I; i++) {
		for (int j = 0; j < MAX_I; j++)
			adj[i][j] = INF;
		adj[i][i] = 0;
	}

}

int mst(int idx) {

	priority_queue<pii, vector<pii>, greater<pii>> pq;

	visit_island[idx] = true;

	for (int i = idx + 1; i < cnt; i++) {
		if (adj[idx][i] == INF)
			continue;
		pq.push(pii(adj[idx][i], i));
	}

	int len = 0, N = 0, nidx;
	pii cur;

	while (!pq.empty()) {

		cur = pq.top(); pq.pop();
		if (visit_island[cur.second])
			continue;
		len += cur.first;
		N++;
		if (N == cnt - 1)
			return len;

		nidx = cur.second;
		visit_island[nidx] = true;

		for (int i = 0; i < cnt; i++) {
			if (visit_island[i])
				continue;

			if (adj[nidx][i] == INF)
				continue;

			pq.push(pii(adj[nidx][i], i));
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	get_island();
	make_adj();
	/*
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (adj[i][j] == INF)
				cout << "@ ";
			else
				cout << adj[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << mst(0) << '\n';

	return 0;
}