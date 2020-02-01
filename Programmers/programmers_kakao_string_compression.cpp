#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 987654321;
	int len;

	len = s.size() / 2;

	string cur = "", prev = "", tmp = "";
	int j, cnt, n;
	if (s.size() == 1)
		return 1;
	for (int i = 1; i <= len; i++) {
		cur = "", prev = "", tmp = "";
		cnt = 1;
		n = s.size() / i - 1;
		for (j = 0; j < i; j++) {
			prev += s[j];
		}
		while (n > 0) {
			for (int k = 0; k < i; k++)
				cur += s[j++];

			if (cur == prev) {
				cnt++;
			}
			else {
				if (cnt != 1)
					tmp += to_string(cnt);
				tmp += prev;
				prev = cur;
				cnt = 1;
			}
			cur = "";
			n--;
		}
		if (cnt != 1)
			tmp += to_string(cnt);
		tmp += prev;

		n = s.size() % i;
		while (n > 0) {
			tmp += s[j++];
			n--;
		}
		if (answer > tmp.size())
			answer = tmp.size();
	}

	return answer;
}