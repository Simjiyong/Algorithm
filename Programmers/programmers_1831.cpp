#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int answer, multiCnt;
void dfs(int n, int plus) {
	if (plus > log(n) / log(3) * 2)
		return;
	if (n == 3) {
		if (plus == 2)
			answer++;
		return;
	}

	if (plus >= 2 && n % 3 == 0)
		dfs(n / 3, plus - 2);
	dfs(n - 1, plus + 1);
}

int solution(int n) {
	answer = 0;
	multiCnt = log(n) / log(3);
	dfs(n, 0);
	return answer;
}

int main() {
	printf("%d\n", solution(2147483647));
	return 0;
}