/*
https://www.acmicpc.net/problem/12865
배낭의 수용 가능 최대무게 k와 물건의 개수 n, 각 물건들의 무게,가치가 주어지고 배낭에 넣을 수 있는 최대 가치를 구하는 문제이다.
물건의 개수가 100개까지 이므로 단순히 시뮬레이션을 돌리면 시간초과이다.
가능한 물건의 조합이 이난 최대 가치를 구하는 문제이므로 dp로 풀 수 있다.
무게는 100000까지 이므로 각 무게를 메모이제이션하고 물건을 순회하면서 현재 물건을 넣었을 때 각 무게에서의 최대 가치를 구하면 된다.
시간복잡도는 O(nk)이고 여기서는 100000*100 = 10000000 < 1억 이므로 1초 이내에 작동한다.
*/

#include <stdio.h>

using namespace std;

int dp[100001];

int main(){
	int n, k, w, v, result = -1;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= k; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w, &v);		
		for (int j = k-w; j>=0 ; j--) {
			if (dp[j] != -1 && dp[j + w] < dp[j] + v)
				dp[j + w] = dp[j] + v;
		}
	}
	for (int i = 0; i <= k; i++) {
		if (result < dp[i])
			result = dp[i];
	}
	printf("%d", result);
}
