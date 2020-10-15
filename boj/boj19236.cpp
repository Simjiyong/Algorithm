#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX_N = 4;

struct Fish
{
	int y;
	int x;
	int dir;

	void operator=(const Fish& a) {
		y = a.y;
		x = a.x;
		dir = a.dir;
	}
};
int board[MAX_N][MAX_N];
Fish fish[MAX_N * MAX_N + 1];
bool isEnd[MAX_N * MAX_N + 1];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int maxSum = -1;
void init() {
	int a, b;
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			cin >> a >> b;
			board[i][j] = a;
			fish[a].y = i;
			fish[a].x = j;
			fish[a].dir = b - 1;
		}
	}
}

void mMemcpy(int dest[MAX_N][MAX_N], int src[MAX_N][MAX_N], Fish destFish[MAX_N * MAX_N + 1], Fish srcFish[MAX_N * MAX_N + 1]) {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			dest[i][j] = src[i][j];
		}
	}

	for (int i = 0; i < MAX_N * MAX_N + 1; i++)
		destFish[i] = srcFish[i];
}

void swapFish(int ny, int nx, int y, int x) {
	int f1, f2;
	Fish tmp;
	f1 = board[y][x];
	f2 = board[ny][nx];

	tmp = fish[f1];
	fish[f1].y = fish[f2].y;
	fish[f1].x = fish[f2].x;

	fish[f2].y = tmp.y;
	fish[f2].x = tmp.x;

	board[y][x] = f2;
	board[ny][nx] = f1;

}

void move(int sy, int sx) {
	int ndir, ny, nx;
	Fish cur;
	for (int i = 1; i <= MAX_N * MAX_N; i++) {
		if (isEnd[i])
			continue;
		cur = fish[i];
		for (int dir = 0; dir < 8; dir++) {
			ndir = (fish[i].dir + dir) % 8;
			ny = fish[i].y + dy[ndir];
			nx = fish[i].x + dx[ndir];

			if (ny < 0 || nx < 0 || ny > MAX_N - 1 || nx > MAX_N - 1)
				continue;
			if (ny == sy && nx == sx)
				continue;

			if (board[ny][nx] == 0) { // empty
				board[ny][nx] = i;
				board[fish[i].y][fish[i].x] = 0;
				fish[i].y = ny;
				fish[i].x = nx;
			}
			else
				swapFish(fish[i].y, fish[i].x, ny, nx);
			fish[i].dir = ndir;
			break;
		}

	}
}


void dfs(int y, int x, int dir, int sum) {
	int tmp[MAX_N][MAX_N];
	Fish tmpFish[MAX_N * MAX_N + 1];
	mMemcpy(tmp, board, tmpFish, fish);
	move(y, x);
	int ny = y, nx = x;
	while (1) {
		ny += dy[dir];
		nx += dx[dir];
		if (ny < 0 || nx < 0 || ny > MAX_N - 1 || nx > MAX_N - 1)
			break;
		if (board[ny][nx] == 0)
			continue;

		int n = board[ny][nx];
		isEnd[n] = true;
		board[ny][nx] = 0;
		dfs(ny, nx, fish[n].dir, sum + n);
		isEnd[n] = false;
		board[ny][nx] = n;
	}
	mMemcpy(board, tmp, fish, tmpFish);

	if (maxSum < sum)
		maxSum = sum;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	int n = board[0][0];
	isEnd[n] = true;
	board[0][0] = 0;
	dfs(0, 0, fish[n].dir, n);
	isEnd[n] = false;
	board[0][0] = n;

	cout << maxSum << '\n';
	return 0;
}