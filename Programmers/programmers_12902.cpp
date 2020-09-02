#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 5000;
const int MOD = 1000000007;

long long D[MAX_N + 1];
int solution(int n) {
	if (n % 2)
		return 0;

	int answer = 0;
	D[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		D[i] = (D[i - 2] * D[2] + 2) % MOD;
		for (int j = i - 4; j > 0; j -= 2) {
			D[i] = (D[i] + D[j] * 2) % MOD;
		}
	}
	answer = D[n] % MOD;
	return answer;
}

int main() {
	printf("%d\n", solution(4578));
	return 0;
}