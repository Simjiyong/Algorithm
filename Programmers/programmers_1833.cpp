#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int idx1, int idx2, int n, vector<vector<int>>& data) {
	int x1, y1, x2, y2, nx, ny;
	x1 = data[idx1][0];
	y1 = data[idx1][1];
	x2 = data[idx2][0];
	y2 = data[idx2][1];

	if (x1 == x2 || y1 == y2)
		return false;

	for (int i = idx1 + 1; i < idx2; i++) {
		nx = data[i][0];
		ny = data[i][1];
		if (nx < max(x1, x2) && ny < max(y1, y2) && nx > min(x1, x2) && ny > min(y1, y2))
			return false;
	}
	return true;
}
int solution(int n, vector<vector<int>> data) {
	int answer = 0;
	sort(data.begin(), data.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (isPossible(i, j, n, data))
				answer++;
		}
	}
	return answer;
}