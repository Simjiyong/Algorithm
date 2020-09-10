#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int MAX_M = 30;
const int MAX_N = 30;
int dy[4] = { 0, 0, 1, 1 };
int dx[4] = { 0, 1, 0, 1 }; // m = y, x = n
bool visit[MAX_M][MAX_N];

bool isPossible(int y, int x, vector<string>& board) {
	int ny, nx;
	if (board[y][x] == ' ')
		return false;
	for (int dir = 0; dir < 4; dir++) {
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (board[y][x] != board[ny][nx])
			return false;
	}
	return true;
}
int pang(int m, int n, vector<string>& board) {
	int res = 0, ny, nx;
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (isPossible(i, j, board)) {
				for (int dir = 0; dir < 4; dir++) {
					ny = i + dy[dir];
					nx = j + dx[dir];
					if (!visit[ny][nx]) {
						res++;
						visit[ny][nx] = true;
					}
				}
			}
		}
	}
	return res;
}

void remove(int m, int n, vector<string>& board) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j])
				board[i][j] = ' ';
		}
	}
}

void drop(int m, int n, vector<string>& board) {
	for (int j = 0; j < n; j++) {
		int i, k;
		i = m - 1;
		while (i >= 0) {
			if (board[i][j] == ' ')
				break;
			i--;
		}
		k = i;
		while (k >= 0) {
			if (board[k][j] != ' ') {
				board[i][j] = board[k][j];
				board[k][j] = ' ';
				i--;
			}
			k--;
		}
	}
}

void print(int m, int n, vector<string> board) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int cnt;
	while (1) {
		cnt = pang(m, n, board);
		if (cnt == 0)
			return answer;
		answer += cnt;
		remove(m, n, board);
		drop(m, n, board);
		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
			visit[i][j] = false;
	}
	return answer;
}