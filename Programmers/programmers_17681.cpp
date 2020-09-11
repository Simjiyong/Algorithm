#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<int> arr;
	for (int i = 0; i < n; i++)
		arr.push_back(arr1[i] | arr2[i]);
	string str;
	for (int i = 0; i < n; i++) {
		str = "";
		int t = 1 << n - 1;
		while (t > 0) {
			if (arr[i] & t)
				str += "#";
			else
				str += " ";
			t >>= 1;
		}
		answer.push_back(str);
	}
	return answer;
}