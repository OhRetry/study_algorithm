/*
기본적인 parametric search 문제. 
랜선의 최대 길이는 2^31 - 1로 mid=(min + max)/2연산에서 overflow가 나지 않도록 min,mid,max는 long long으로 선언한다.
*/

#include <iostream>
#include <climits>

using namespace std;

int k, n;
int arr[10000];

bool calc(int x) {
	int result = 0;
	for (int i = 0; i < k; i++) {
		result += arr[i] / x;
	}
	return result >= n ? true : false;
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	long long min_n = 1, mid_n, max_n = INT_MAX;
	int result = -1;
	while (min_n <= max_n) {
		mid_n = (min_n + max_n) / 2;
		if (calc(mid_n)) {
			min_n = mid_n + 1;
			result = mid_n;
		}
		else {
			max_n = mid_n - 1;
		}
	}
	cout << result << endl;
}
