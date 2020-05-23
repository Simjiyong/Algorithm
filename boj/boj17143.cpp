#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

const int MAX_R = 100;
const int MAX_C = 100;
const int MAX_M = MAX_R * MAX_C;
struct Shark
{
	int s; // speed
	int d; // dir
	int size; // size

	Shark() {
		s = 0;
		d = 0;
		size = 0;
	}

	Shark(int s, int d, int z) {
		this->s = s;
		this->d = d;
		size = z;
	}
};
int board[MAX_R + 1][MAX_C + 1];
int R, C, M;
Shark shark[MAX_M + 1];
int cnt = 1;
int king;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void print(int src[MAX_R + 1][MAX_C + 1]) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << src[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void init() {
	cin >> R >> C >> M;

	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2)
			s %= (R - 1) * 2;
		else
			s %= (C - 1) * 2;
		shark[cnt] = Shark(s, d - 1, z);
		board[r][c] = cnt;
		cnt++;
	}
	king = 0;
}

int fishing() {
	int idx;
	for (int i = 1; i <= R; i++) {
		if (board[i][king] != 0) {
			idx = board[i][king];
			board[i][king] = 0;
			return shark[idx].size;
		}
	}
	return 0;
}

void mMemset(int tmp[MAX_R + 1][MAX_C + 1]) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			tmp[i][j] = 0;
		}
	}
}

void move(int y, int x, int tmp[MAX_R + 1][MAX_C + 1]) {
	int ny, nx, idx, d, s;
	ny = y;
	nx = x;
	idx = board[y][x];
	d = shark[idx].d;
	s = 0;

	while (s < shark[idx].s) {
		ny += dy[d];
		nx += dx[d];
		if (ny < 1 || nx < 1 || ny > R || nx > C) {
			d += d % 2 ? -1 : 1;
			ny += dy[d] * 2;
			nx += dx[d] * 2;
		}
		s++;
	}
	shark[idx].d = d;
	int cidx = tmp[ny][nx];
	if (cidx && shark[idx].size < shark[cidx].size)
		return;
	tmp[ny][nx] = idx;
}

void mMemcpy(int dest[MAX_R + 1][MAX_C + 1], int src[MAX_R + 1][MAX_C + 1]) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void moveShark() {
	int idx;
	int tmp[MAX_R + 1][MAX_C + 1];
	mMemset(tmp);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] == 0)
				continue;
			idx = board[i][j];
			move(i, j, tmp);
		}
	}
	mMemcpy(board, tmp);
}

int main() {
	int answer = 0;
	init();
	while (king < C) {
		king++;
		answer += fishing();
		moveShark();
	}

	cout << answer;
	return 0;
}