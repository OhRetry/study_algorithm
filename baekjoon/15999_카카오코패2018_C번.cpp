/*
https://www.acmicpc.net/problem/15999
경우의 수에 대한 문제로, 현재 상태에서 모든 면이 연결되어 있는 타일만 이전 상태와 현재 상태가 다를 수 있다는 점만 알아낸다면
W/B의 2가지에 대해 2^changable 로 경우의 수를 구할 수 있다.
나머지 연산은 덧셈,뺄셈,곱셈에 대해 닫혀있으므로, result = (2^changable)%1000000007 에서 
2를 곱할 때마다 나머지 연산자를 적용해 주면 된다.
*/


#include <stdio.h>
#define MAXIMUM 1000000007

char arr[2000][2000];
int main()
{
	int n, m , changable = 0;
	int result = 1;
	char color[2001];
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", color);
		for (int k = 0; k < m; k++) {
			if (color[k] == 'W')
				arr[i][k] = 0;
			else
				arr[i][k] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (	i - 1 >= 0 && arr[i][k] != arr[i - 1][k] ||
				i + 1 < n  && arr[i][k] != arr[i + 1][k] ||
				k - 1 >= 0 && arr[i][k] != arr[i][k - 1] ||
				k + 1 < m  && arr[i][k] != arr[i][k + 1]
				) {continue;}			
			changable++;			
		}
	}
	
	int p = 2,k = 1;
	while (p <= MAXIMUM) {
		p *= 2;
		k++;
	}
	
	for (int i = 0; i < changable; i++) {
		result *= 2;
		result = result % MAXIMUM;
	}

	printf("%d", result);
}
