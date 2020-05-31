#include <iostream>
#include <algorithm>
using namespace std;
const int TURN = 10;
const int MAX_N = 20;
struct Horse {
	int y;
	int x;
	bool finish;
};

int answer;
int dice[TURN];
Horse horse[4];

bool visit[4][MAX_N + 1];
int board[6][MAX_N + 1] = {
	{},
	{10, 13, 16, 19, 25, 30, 35, 40},
	{20, 22, 24, 25, 30, 35, 40},
	{30, 28, 27, 26, 25, 30 ,35, 40},
	{25, 30, 35, 40},
	{40}
};

void init() {
	for (int i = 0; i < TURN; i++)
		cin >> dice[i];

	for (int i = 1; i <= MAX_N; i++) {
		board[0][i] = i * 2;
	}

}

void dfs(int cur, int cnt, int score) {
	if (cnt == 10) {
		answer = max(answer, score);
		return;
	}
	if (horse[cur].finish)
		return;

	int y, x, ny, nx;
	y = horse[cur].y;
	x = horse[cur].x;
	ny = y;
	nx = x + dice[cnt];
	if (nx > MAX_N || board[ny][nx] == 0) {
		horse[cur].finish = true;
		visit[y][x] = false;
		for (int i = 0; i < 4; i++) {
			dfs(i, cnt + 1, score);
		}
		horse[cur].finish = false;
		visit[y][x] = true;
	}
	else {
		if (board[ny][nx] == 40)
			ny = 5, nx = 0;
		else if (0 < y && y < 4 && board[ny][nx] % 5 == 0)
			nx = board[ny][nx] / 5 - 5, ny = 4;
		else if (y == 0 && board[ny][nx] % 10 == 0)
			ny = board[ny][nx] / 10, nx = 0;

		if (visit[ny][nx])
			return;

		horse[cur].y = ny;
		horse[cur].x = nx;
		visit[ny][nx] = true;
		visit[y][x] = false;
		for (int i = 0; i < 4; i++) {
			dfs(i, cnt + 1, score + board[ny][nx]);
		}
		horse[cur].y = y;
		horse[cur].x = x;
		visit[ny][nx] = false;
		visit[y][x] = true;
	}
}

int main() {
	init();
	for (int i = 0; i < 4; i++) {
		dfs(i, 0, 0);
	}
	cout << answer << '\n';
	return 0;
}