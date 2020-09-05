#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 201;
const int INF = 987654321;
int D[MAX_N][MAX_N][2]; // 0 : max, 1 : min

int solve(int start, int end, int type, vector<string>& arr) {
	if (D[start][end][type] != INF && D[start][end][type] != -INF)
		return D[start][end][type];

	for (int i = start + 1; i <= end - 1; i += 2) {
		if (type == 0) {
			if (arr[i] == "+")
				D[start][end][type] = max(D[start][end][type], solve(start, i - 1, 0, arr) + solve(i + 1, end, 0, arr));
			else
				D[start][end][type] = max(D[start][end][type], solve(start, i - 1, 0, arr) - solve(i + 1, end, 1, arr));
		}
		else {
			if (arr[i] == "+")
				D[start][end][type] = min(D[start][end][type], solve(start, i - 1, 1, arr) + solve(i + 1, end, 1, arr));
			else
				D[start][end][type] = min(D[start][end][type], solve(start, i - 1, 1, arr) - solve(i + 1, end, 0, arr));
		}
	}

	return D[start][end][type];
}

void init() {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			D[i][j][0] = -INF;
			D[i][j][1] = INF;
		}
	}
}

int solution(vector<string> arr)
{
	int answer = 1;
	int num;
	init();
	for (int i = 0; i < arr.size(); i += 2) {
		num = stoi(arr[i]);
		D[i][i][0] = D[i][i][1] = num;
	}

	answer = solve(0, arr.size() - 1, 0, arr);
	return answer;
}