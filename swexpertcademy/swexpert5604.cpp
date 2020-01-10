#include <iostream>

using namespace std;

typedef long long ll;
const ll SUM = 45; // 0~9�� ��
ll A, B;
ll answer;

void calc(ll n, ll digit) {  // �� �ڸ��� ������ �����ִ� �Լ�
	while (n > 0) {
		answer += (n % 10) * digit;
		n /= 10;
	}
}

void setNum(ll digit) { // A�� 1�� �ڸ��� 0���� B�� 1�� �ڸ��� 9�� ����
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
			answer += SUM * digit * (B - A + 1); // 0����9������ ���� �� �ڸ����� ������ ��ŭ ������
			digit *= 10;
		}
		cout << "#" << tc << " " << answer << "\n";
	}
	return 0;
}