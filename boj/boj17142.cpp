#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 50;
const int INF = 987654321;

int board[MAX_N][MAX_N];
int N, M;
int answer = INF;
int blankCnt;
vector<pii> v;
vector<int> orders;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
void init() {
	cin >> N >> M;

	blankCnt = N * N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				v.push_back(pii(i, j));
				blankCnt--;
			}
			else if (board[i][j] == 1)
				blankCnt--;
		}
	}
}

void mMemcpy(int dest[MAX_N][MAX_N], int src[MAX_N][MAX_N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void print(int tmp[MAX_N][MAX_N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
int check() {
	int size, time = 0, cnt = 0;
	int y, x, ny, nx;

	int tmp[MAX_N][MAX_N];
	queue<pii> q;

	mMemcpy(tmp, board);
	for (int i = 0; i < orders.size(); i++) {
		y = v[orders[i]].first;
		x = v[orders[i]].second;
		tmp[y][x] = 3;
		q.push(pii(y, x));
	}

	while (!q.empty()) {
		size = q.size();
		while (size-- > 0) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				ny = y + dy[dir];
				nx = x + dx[dir];
				if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
					continue;
				if (tmp[ny][nx] == 1 || tmp[ny][nx] == 3)
					continue;
				if (tmp[ny][nx] != 2) {
					cnt++;
				}
				tmp[ny][nx] = 3;
				q.push(pii(ny, nx));
			}
		}
		time++;
		if (cnt == blankCnt) {
			return time;
		}
		if (answer <= time) {
			return INF;
		}
	}
	return INF;
}


void make_permutation(int here, int cnt) {
	if (cnt == M) {
		answer = min(answer, check());
		return;
	}
	int y, x;
	for (int i = here; i < v.size(); i++) {
		y = v[i].first;
		x = v[i].second;
		orders.push_back(i);
		make_permutation(i + 1, cnt + 1);
		orders.pop_back();
	}

}
int main() {
	init();
	if (blankCnt == 0) {
		cout << 0;
		return 0;
	}

	make_permutation(0, 0);
	if (answer == INF)
		answer = -1;
	cout << answer;
	return 0;
}