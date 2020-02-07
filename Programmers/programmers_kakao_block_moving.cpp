#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAX_N = 100;
struct Machine {
	int y1;
	int x1;
	int y2;
	int x2;
	int dir;
	Machine() {}
	Machine(int Y1, int X1, int Y2, int X2, int Dir) {
		y1 = min(Y1, Y2);
		y2 = max(Y1, Y2);
		x1 = min(X1, X2);
		x2 = max(X1, X2);
		dir = Dir;
	}
};

queue<Machine> q;

bool visit[MAX_N + 2][MAX_N + 2][2]; // 0 : 가로, 1: 세로

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };


int rotate_y[2][4][2] = { {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
						 ,{{0, -1}, {0, -1}, {1, 0}, {1, 0}} };

int rotate_x[2][4][2] = { {{0, -1}, {0, -1}, {1, 0}, {1, 0}}
						 ,{{0, 1}, {0, -1}, {1, 0}, {-1, 0}} };

void move(Machine cur, vector<vector<int>> board) {
	int nx1, nx2, ny1, ny2, ndir;
	int n = board.size();

	for (int dir = 0; dir < 4; dir++) {
		nx1 = cur.x1 + dx[dir];
		nx2 = cur.x2 + dx[dir];
		ny1 = cur.y1 + dy[dir];
		ny2 = cur.y2 + dy[dir];
		ndir = cur.dir;

		if (nx1 < 1 || nx1 > n || nx2 < 1 || nx2 > n || ny1 < 1 || ny1 > n || ny2 < 1 || ny2 > n)
			continue;

		if (board[ny2 - 1][nx2 - 1] || board[ny1 - 1][nx1 - 1])
			continue;

		Machine next(ny1, nx1, ny2, nx2, ndir);
		if (visit[next.y2][next.x2][ndir])
			continue;

		visit[next.y2][next.x2][ndir] = true;
		q.push(next);
	}
	return;
}
void rotate(Machine cur, vector<vector<int>> board) {
	int nx1, nx2, ny1, ny2, ndir;
	int n = board.size();

	if (cur.dir == 0)
		ndir = 1;
	else
		ndir = 0;

	for (int i = 0; i < 4; i++) {
		ny1 = cur.y1 + rotate_y[cur.dir][i][0];
		nx1 = cur.x1 + rotate_x[cur.dir][i][0];

		ny2 = cur.y2 + rotate_y[cur.dir][i][1];
		nx2 = cur.x2 + rotate_x[cur.dir][i][1];

		if (nx1 < 1 || nx1 > n || nx2 < 1 || nx2 > n || ny1 < 1 || ny1 > n || ny2 < 1 || ny2 > n)
			continue;


		if (cur.dir == 0) {
			if (i < 2 && (board[ny2 - 1][cur.x2 - 1] || board[ny2 - 1][nx2 - 1]))
				continue;
			if (i >= 2 && (board[ny1 - 1][cur.x1 - 1] || board[ny1 - 1][nx1 - 1]))
				continue;
		}

		if (cur.dir == 1) {
			if (i < 2 && (board[cur.y2 - 1][nx2 - 1] || board[ny2 - 1][nx2 - 1]))
				continue;
			if (i >= 2 && (board[cur.y1 - 1][nx1 - 1] || board[ny1 - 1][nx1 - 1]))
				continue;
		}

		Machine next(ny1, nx1, ny2, nx2, ndir);
		if (visit[next.y2][next.x2][ndir])
			continue;

		visit[next.y2][next.x2][ndir] = true;
		q.push(next);

	}

}
int solution(vector<vector<int>> board) {
	int answer = 0;

	int size, n = board.size();
	q.push(Machine(1, 1, 1, 2, 0));
	visit[1][2][0] = true;
	Machine cur;
	while (!q.empty()) {
		size = q.size();
		answer++;
		while (size-- > 0) {
			cur = q.front(); q.pop();
			move(cur, board);
			rotate(cur, board);

			if (visit[n][n][0] || visit[n][n][1])
				return answer;
		}
	}

	return answer;
}