#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int dist, vector<int>& rocks, int n) {
    int prev = rocks[0];
    for (int i = 1; i < rocks.size(); i++) {
        if (rocks[i] - prev < dist) {
            n--;
        }
        else {
            prev = rocks[i];
        }
    }
    return n >= 0 ? true : false;
}

int binarySearch(int left, int right, vector<int>& rocks, int n) {
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (isPossible(mid, rocks, n)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return right;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    answer = binarySearch(1, 1000000000, rocks, n);
    return answer;
}

int main() {
    return 0;
}