#include <string>
#include <vector>

using namespace std;
const int MAX_N = 14;
int d[MAX_N + 1];
int solution(int n) {
	int answer = 0;
	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			d[i] += d[j] * d[i - j - 1];
		}
	}
	answer = d[n];
	return answer;
}