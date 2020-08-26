#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long x, y, z;

int binarySearch(int left, int right) {
	int mid, res = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		int z2 = 100 * (y + mid) / (x + mid);
		if (z2 > z) {
			res = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return res;
}

int main() {
	scanf(" %d %d", &x, &y);
	z = 100 * y / x;
	if (z >= 99)
		printf("-1\n");
	else
		printf("%lld\n", binarySearch(1, 1000000000));

	return 0;
}