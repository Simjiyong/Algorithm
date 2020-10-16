#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 10000;
const int MAX_Y = 6;
const int MAX_X = 4;

int N;
int green[MAX_Y][MAX_X], blue[MAX_Y][MAX_X];

void drop(int x, int diffY, int diffX, int n, int tile[MAX_Y][MAX_X]) {
	int y = 0;
	while (y + diffY < MAX_Y) {
		if (tile[y][x] != 0 || tile[y + diffY][x + diffX] != 0)
			break;
		y++;
	}
	y--;
	tile[y][x] = tile[y + diffY][x + diffX] = n;
}

void print(int tile[MAX_Y][MAX_X]) {
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++) {
			cout << tile[i][j] << " ";
		}
		cout << '\n';
	}
}

void mMemcpy(int dest[MAX_Y][MAX_X], int src[MAX_Y][MAX_X]) {
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

bool isSame(int tile1[MAX_Y][MAX_X], int tile2[MAX_Y][MAX_X]) {
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++) {
			if (tile1[i][j] != tile2[i][j])
				return false;
		}
	}
	return true;
}
void update(int tile[MAX_Y][MAX_X]) {
	int cy, y, x;
	int tmp[MAX_Y][MAX_X];
	while (1) {
		x = 0;
		mMemcpy(tmp, tile);
		while (x < MAX_X) { // 세로 내리기
			cy = y = MAX_Y - 1;
			while (cy >= 0) {
				if (tile[cy][x] != 0) {
					if ((x + 1 < MAX_X && tile[cy][x] == tile[cy][x + 1])
						|| (x - 1 >= 0 && tile[cy][x] == tile[cy][x - 1])) {
						while (y > cy) {
							tile[y][x] = 0;
							y--;
						}
					}
					tile[y][x] = tile[cy][x];
					y--;
				}
				cy--;
			}
			while (y >= 0) {
				tile[y][x] = 0;
				y--;
			}
			x++;
		}
		x = 0;
		while (x < MAX_X - 1) { // 가로 내리기
			cy = y = MAX_Y - 1;
			while (cy >= 0) {
				if (tile[cy][x] == 0 && tile[cy][x + 1] == 0) {
					cy--;
				}
				else if (tile[cy][x] == tile[cy][x + 1]) {
					tile[y][x] = tile[cy][x];
					tile[y][x + 1] = tile[cy][x + 1];
					cy--;
					y--;
				}
				else {
					while (y > cy) {
						tile[y][x] = 0;
						tile[y][x + 1] = 0;
						y--;
					}
					tile[y][x] = tile[cy][x];
					tile[y][x + 1] = tile[cy][x + 1];
					y--;
					cy--;
				}
			}
			while (y >= 0) {
				tile[y][x] = 0;
				tile[y][x + 1] = 0;
				y--;
			}
			x++;
		}
		if (isSame(tmp, tile))
			break;
	}

}

int remove(int tile[MAX_Y][MAX_X]) {
	int res = 0;

	bool flag;
	int cnt;
	while (1) {
		cnt = 0;
		for (int y = 2; y < MAX_Y; y++) {
			flag = true;
			for (int x = 0; x < MAX_X; x++) {
				if (tile[y][x] == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int x = 0; x < MAX_X; x++)
					tile[y][x] = 0;
				cnt++;
			}
		}
		if (cnt == 0)
			break;
		res += cnt;
		update(tile);
	}
	return res;

}

void move(int tile[MAX_Y][MAX_X]) {
	int cnt = 0;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < MAX_X; x++) {
			if (tile[y][x] != 0) {
				cnt++;
				break;
			}
		}
	}

	int tmp[MAX_Y][MAX_X] = { 0, };

	for (int y = 0; y < MAX_Y - cnt; y++) {
		for (int x = 0; x < MAX_X; x++) {
			tmp[y + cnt][x] = tile[y][x];
		}
	}

	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			tile[y][x] = tmp[y][x];
		}
	}

}
int getCnt(int tile[MAX_Y][MAX_X]) {
	int res = 0;
	for (int i = 0; i < MAX_Y; i++) {
		for (int j = 0; j < MAX_X; j++) {
			if (tile[i][j] != 0)
				res++;
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int t, y, x;
	int score = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		cin >> t >> y >> x;

		if (t == 1) {
			drop(x, 0, 0, i, green);
			drop(y, 0, 0, i, blue);
		}
		else if (t == 2) {
			drop(x, 0, 1, i, green);
			drop(y, 1, 0, i, blue);
		}
		else if (t == 3) {
			drop(x, 1, 0, i, green);
			drop(y, 0, 1, i, blue);
		}

		score += remove(green) + remove(blue);

		move(green);
		move(blue);
	}
	cout << score << '\n';
	cnt = getCnt(green) + getCnt(blue);
	cout << cnt << '\n';

	return 0;
}