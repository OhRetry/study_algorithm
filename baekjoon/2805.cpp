/*
기본적인 parametric search 문제. 
calc함수에서 조건에 맞는지 확인하는 중에 overflow가 날 수 있으므로 result를 갱신할 때마다 이미 조건이 만족되었는지 확인해 줘야 한다.
*/
#include <iostream>
#include <climits>

using namespace std;

int arr[1000000];
int n, m;
bool calc(int x) {
	long long result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - x > 0){
			result += arr[i] - x;        
			if(result >= m)
				return true;
		}
	}
	return result >= m ? true : false;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int low = 0, mid, high = 1000000000;
	int result = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (calc(mid)) {
			low = mid + 1;
			result = mid;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;
}
