#include <iostream>
#include <deque>
#include <map>

using namespace std;
const int MAX_N = 12;
const int MAX_K = 10;
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;
struct Chess
{
	int y;
	int x;
	int dir;
	Chess() {
		y = NULL;
		x = NULL;
		dir = NULL;
	}

	Chess(int y, int x, int dir) {
		this->y = y;
		this->x = x;
		this->dir = dir;
	}
};
int board[MAX_N][MAX_N];
int N, K;
Chess c[MAX_K + 1];
deque<int> dq[MAX_N][MAX_N];
map<int, int> m;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 }; //rlud;
void init() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		cin >> c[i].y >> c[i].x >> c[i].dir;
		c[i].dir--;
		c[i].y--;
		c[i].x--;
		dq[c[i].y][c[i].x].push_back(i);
		m[i] = 0;
	}
}

bool white(int y, int x, int ny, int nx, int k) {
	int s, idx;
	s = m[k];
	for (int i = s; i < dq[y][x].size(); i++) {
		idx = dq[y][x][i];
		dq[ny][nx].push_back(idx);
		m[idx] = dq[ny][nx].size() - 1;
		c[idx].y = ny;
		c[idx].x = nx;
	}
	dq[y][x].erase(dq[y][x].begin() + s, dq[y][x].end());
	if (dq[ny][nx].size() >= 4)
		return true;
	return false;
}

bool red(int y, int x, int ny, int nx, int k) {
	int s, idx;
	s = m[k];
	for (int i = dq[y][x].size() - 1; i >= s; i--) {
		idx = dq[y][x][i];
		dq[ny][nx].push_back(idx);
		m[idx] = dq[ny][nx].size() - 1;
		c[idx].y = ny;
		c[idx].x = nx;
	}
	dq[y][x].erase(dq[y][x].begin() + s, dq[y][x].end());
	if (dq[ny][nx].size() >= 4)
		return true;
	return false;
}

bool blue(int y, int x, int k) {
	if (c[k].dir % 2 == 0)
		c[k].dir++;
	else
		c[k].dir--;

	int ny, nx;
	ny = y + dy[c[k].dir];
	nx = x + dx[c[k].dir];
	if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1)
		return false;
	if (board[ny][nx] == BLUE)
		return false;
	if (board[ny][nx] == WHITE)
		return white(y, x, ny, nx, k);
	else if (board[ny][nx] == RED)
		return red(y, x, ny, nx, k);
}

bool turn() {
	int y, x, ny, nx, dir;
	for (int i = 1; i <= K; i++) {
		y = c[i].y;
		x = c[i].x;
		dir = c[i].dir;
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) {
			if (blue(y, x, i))
				return true;
		}
		else if (board[ny][nx] == WHITE) {
			if (white(y, x, ny, nx, i))
				return true;
		}
		else if (board[ny][nx] == RED) {
			if (red(y, x, ny, nx, i))
				return true;;
		}
		else if (board[ny][nx] == BLUE) {
			if (blue(y, x, i))
				return true;
		}
	}
	return false;
}

int main() {

	init();
	int answer = 0;
	while (1) {
		answer++;
		if (turn())
			break;
		if (answer > 1000) {
			answer = -1;
			break;
		}
	}
	cout << answer << '\n';
	return 0;
}