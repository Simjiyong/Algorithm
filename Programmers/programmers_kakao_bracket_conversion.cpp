#include <string>
#include <vector>

using namespace std;

void divide(const string w, string& u, string& v) {
	int balanced;
	if (w[0] < ')')
		balanced = -1;
	else
		balanced = 1;
	u = w[0];
	for (int i = 1; i < w.size(); i++) {
		if (balanced != 0) {
			if (w[i] < ')')
				balanced--;
			else
				balanced++;
			u += w[i];
		}
		else {
			v += w[i];
		}
	}
}

bool isCorrect(const string u) {
	int open = 0;
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(')
			open++;
		else
			open--;

		if (open < 0)
			return false;
	}
	return true;
}

string reverse(string u) {
	string tmp = "";

	for (int i = 1; i < u.size() - 1; i++) {
		if (u[i] == '(')
			tmp += ')';
		else
			tmp += '(';
	}
	return tmp;
}
string solve(string w) {
	string u = "", v = "";
	if (w == "")
		return "";
	divide(w, u, v);

	if (isCorrect(u)) {
		return u + solve(v);
	}
	else {
		return "(" + solve(v) + ")" + reverse(u);
	}

}
string solution(string p) {
	string answer = "";

	string w, u, v;
	if (p == "") {
		return answer;
	}

	answer = solve(p);

	return answer;
}