#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int MAX_R = 50;
const int MAX_C = 50;

int R, C, T;
int board[MAX_R][MAX_C];
pii uc, dc;
queue<pii> q;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, 1, -1, 0 };// urld
void init() {
	cin >> R >> C >> T;
	bool flag = true;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				if (flag) {
					uc = pii(i, j);
					flag = false;
				}
				else
					dc = pii(i, j);
			}
			else if (board[i][j] != 0)
				q.push(pii(i, j));
		}
	}
}

void mMemset(int tmp[MAX_R][MAX_C]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmp[i][j] = 0;
		}
	}
}
void expand() {
	int y, x, ny, nx;
	int tmp[MAX_R][MAX_C];
	int cnt;

	mMemset(tmp);
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		cnt = 0;
		if (board[y][x] / 5 == 0)
			continue;
		for (int dir = 0; dir < 4; dir++) {
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny > R - 1 || nx > C - 1)
				continue;
			if (board[ny][nx] == -1)
				continue;
			tmp[ny][nx] += board[y][x] / 5;
			cnt++;
		}
		board[y][x] -= (board[y][x] / 5) * cnt;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			board[i][j] += tmp[i][j];
		}
	}
}

void clean() {
	int y, x;
	y = uc.first;
	x = uc.second;
	for (int i = y - 1; i > 0; i--) {
		board[i][x] = board[i - 1][x];
	}
	for (int i = x; i < C - 1; i++) {
		board[0][i] = board[0][i + 1];
	}
	for (int i = 0; i < y; i++) {
		board[i][C - 1] = board[i + 1][C - 1];
	}
	for (int i = C - 1; i > x + 1; i--) {
		board[y][i] = board[y][i - 1];
	}
	board[y][x + 1] = 0;


	y = dc.first;
	x = dc.second;
	for (int i = y + 1; i < R - 1; i++) {
		board[i][x] = board[i + 1][x];
	}
	for (int i = x; i < C - 1; i++) {
		board[R - 1][i] = board[R - 1][i + 1];
	}
	for (int i = R - 1; i > y; i--) {
		board[i][C - 1] = board[i - 1][C - 1];
	}
	for (int i = C - 1; i > x + 1; i--) {
		board[y][i] = board[y][i - 1];
	}
	board[y][x + 1] = 0;

}
void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int getSum() {
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == -1)
				continue;
			sum += board[i][j];
		}
	}
	return sum;
}

void makeQueue() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != 0 && board[i][j] != -1)
				q.push(pii(i, j));
		}
	}
}

int main() {
	int answer = 0;
	init();
	while (T--) {
		expand();
		clean();
		makeQueue();
	}
	answer = getSum();
	cout << answer;
	return 0;
}