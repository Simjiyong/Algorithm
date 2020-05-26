#include <iostream>
#include <deque>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 50;
const int MAX_M = 50;
const int CW = 0;
const int CCW = 1;

int N, M, T;
int sum, cnt;
deque<int> dq[MAX_N + 1];

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

void init() {
	cin >> N >> M >> T;
	int n;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> n;
			dq[i].push_back(n);
			sum += n;
			cnt++;
		}
	}
}

void rotate(int idx, int d, int k) {
	while (k--) {
		if (d == CW) {
			dq[idx].push_front(dq[idx].back());
			dq[idx].pop_back();
		}
		else {
			dq[idx].push_back(dq[idx].front());
			dq[idx].pop_front();
		}
	}
}

bool bfs(int cy, int cx) {
	queue<pii> q;
	q.push(pii(cy, cx));
	bool flag = true;
	int y, x, ny, nx, num;
	num = dq[cy][cx];
	dq[cy][cx] = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		sum -= num;
		cnt--;
		for (int dir = 0; dir < 4; dir++) {
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny < 1 || ny > N)
				continue;

			if (nx < 0)
				nx = M - 1;
			if (nx > M - 1)
				nx = 0;

			if (dq[ny][nx] != num)
				continue;
			dq[ny][nx] = 0;
			q.push(pii(ny, nx));
			flag = false;
		}
	}
	if (flag) {
		sum += num;
		cnt++;
		dq[cy][cx] = num;
		return false;
	}
	return true;
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dq[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
bool remove() {
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (dq[i][j] == 0)
				continue;
			if (bfs(i, j))
				flag = true;
		}
	}
	return flag;
}
void update() {
	float avg = (float)sum / cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (dq[i][j] == 0 || dq[i][j] == avg)
				continue;

			if (dq[i][j] < avg) {
				dq[i][j]++;
				sum++;
			}
			else {
				dq[i][j]--;
				sum--;
			}
		}
	}
}

int main() {

	init();
	int x, d, k;

	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		for (int j = 1; j * x <= N; j++) {
			if (M - k < k)
				rotate(j * x, !d, M - k);
			else
				rotate(j * x, d, k);
		}
		if (!remove()) {
			update();
		}
	}
	cout << sum << '\n';
	return 0;
}