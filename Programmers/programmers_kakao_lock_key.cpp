#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 20;
vector<pii> blank;

int mKey[MAX_N + 1][MAX_N + 1][4];

int board[3 * MAX_N][3 * MAX_N];
int N, M, cnt;

void rotate(vector<vector<int>> key) {
	int n = key.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mKey[i][j][0] = key[i][j];
		}
	}

	for (int dir = 1; dir < 4; dir++) {
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n - i; j++) {

				mKey[j][n - i - 1][dir] = mKey[i][j][dir - 1];

				mKey[n - i - 1][n - 1 - j][dir] = mKey[j][n - i - 1][dir - 1];

				mKey[n - 1 - j][i][dir] = mKey[n - i - 1][n - 1 - j][dir - 1];

				mKey[i][j][dir] = mKey[n - 1 - j][i][dir - 1];
			}
		}

		if (n % 2 == 1) {
			mKey[n / 2][n / 2][dir] = mKey[n / 2][n / 2][dir - 1];
		}
	}
}

bool isUnlock(int sy, int sx, int dir) {

	int mCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i + sy][j + sx] == -1)
				continue;

			if (board[i + sy][j + sx] == 1 && mKey[i][j][dir] == 1)
				return false;
			if (board[i + sy][j + sx] == 0 && mKey[i][j][dir] == 0)
				return false;
			if (board[i + sy][j + sx] == 0 && mKey[i][j][dir] == 1)
				mCnt++;
		}
	}
	if (mCnt == cnt)
		return true;
	else
		return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;

	memset(board, -1, sizeof(board));
	N = key.size(), M = lock.size();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (lock[i][j] == 0)
				cnt++;
		}
	}

	rotate(key);


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			board[i + N - 1][j + N - 1] = lock[i][j];
		}
	}

	for (int i = 0; i < M + N - 1; i++) {
		for (int j = 0; j < M + N - 1; j++) {
			for (int dir = 0; dir < 4; dir++) {
				if (isUnlock(i, j, dir))
					return true;
			}
		}
	}

	return false;
}
