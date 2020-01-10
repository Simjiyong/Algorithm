#include <iostream>

using namespace std;

typedef long long ll;
const ll SUM = 45; // 0~9의 합
ll A, B;
ll answer;

void calc(ll n, ll digit) {  // 각 자리의 수들을 더해주는 함수
	while (n > 0) {
		answer += (n % 10) * digit;
		n /= 10;
	}
}

void setNum(ll digit) { // A는 1의 자리를 0으로 B는 1의 자리를 9로 만듦
	while (A % 10 != 0) {
		calc(A, digit);
		if (A == B)
			return;
		A++;
	}
	while (B % 10 != 9) {
		calc(B, digit);
		if (A == B)
			return;
		B--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	ll digit;
	for (int tc = 1; tc <= T; tc++) {
		cin >> A >> B;
		answer = 0;
		digit = 1;
		while (1) {
			setNum(digit);
			if (A == B)
				break;
			B /= 10;
			A /= 10;
			answer += SUM * digit * (B - A + 1); // 0부터9까지의 합이 각 자리수에 나오는 만큼 더해줌
			digit *= 10;
		}
		cout << "#" << tc << " " << answer << "\n";
	}
	return 0;
}