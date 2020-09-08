#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 100000;

int d[MAX_N][2];
int solution(vector<int> sticker)
{
	int answer = 0;
	int N = sticker.size();
	if (N == 1)
		return sticker[0];
	if (N == 2)
		return max(sticker[0], sticker[1]);
	d[0][0] = sticker[0];
	d[1][0] = max(d[0][0], sticker[1]);
	for (int i = 2; i < N - 1; i++) {
		d[i][0] = max(d[i - 1][0], sticker[i] + d[i - 2][0]);
	}

	d[1][1] = sticker[1];
	d[2][1] = max(d[1][1], sticker[2]);
	for (int i = 3; i < N; i++) {
		d[i][1] = max(d[i - 1][1], sticker[i] + d[i - 2][1]);
	}
	answer = max(d[N - 2][0], d[N - 1][1]);
	return answer;
}