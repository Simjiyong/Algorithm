#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
const int INF = 987654321;

int N;
int board[MAX_N + 1][MAX_N + 1];
int answer = INF;
void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
}
void print(int area[MAX_N + 1][MAX_N + 1]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << area[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void mMemset(int target[MAX_N + 1][MAX_N + 1]) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			target[i][j] = 0;
		}
	}
}

int divide(int d1, int d2, int x, int y) {
	if (x + d1 + d2 > N)
		return INF;
	if (y - d1 < 1 || y + d2 > N)
		return INF;
	int ny = y, nx = x;
	int area[MAX_N + 1][MAX_N + 1];
	int sum[5] = { 0, };

	mMemset(area);

	int i = 0, j = 0;
	while (1) {
		if (i > d1 || i > d2)
			break;
		for (int k = y - i; k <= y + i; k++) {
			area[x + i][k] = 5;
		}
		for (int k = y - d1 + d2 - i; k <= y - d1 + d2 + i; k++) {
			area[x + d1 + d2 - i][k] = 5;
		}
		i++;
	}
	j = 1;
	while (1) {
		if (i > d1)
			break;
		for (int k = y - i; k <= y + d2 - j; k++) {
			area[x + i][k] = 5;
		}
		i++, j++;
	}
	while (1) {
		if (i > d2)
			break;
		for (int k = y - d1 + d2 - i; k <= y + d2 - j; k++) {
			area[x + d1 + d2 - i][k] = 5;
		}
		i++, j++;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (area[i][j] == 5) {
				sum[area[i][j] - 1] += board[i][j];
				continue;
			}
			else if (1 <= i && i < x + d1 && 1 <= j && j <= y)
				area[i][j] = 1;
			else if (1 <= i && i <= x + d2 && y < j && j <= N)
				area[i][j] = 2;
			else if (x + d1 <= i && i <= N && 1 <= j && j < y - d1 + d2)
				area[i][j] = 3;
			else if (x + d2 < i && i <= N && y - d1 + d2 <= j && j <= N)
				area[i][j] = 4;
			sum[area[i][j] - 1] += board[i][j];
		}
	}
	sort(sum, sum + 5);
	return sum[4] - sum[0];
}

int main() {
	init();

	for (int d1 = 1; d1 < N; d1++) {
		for (int d2 = 1; d2 < N; d2++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					answer = min(answer, divide(d1, d2, i, j));
				}
			}
		}
	}
	cout << answer;
	return 0;
}