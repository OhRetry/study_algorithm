//BFS를 이용한 DP문제.
//노드 간의 거리가 1로 같으므로 n에서부터 BFS를 통해 방문하면 최단거리가 된다.
//시간복잡도는 T(DPMAX+1)이다. 즉 n의 범위에 선형적인 시간복잡도.
//while문 안에서 k에 도달했다면 도중에 종료하도록 조건문을 넣는 것도 괜찮아 보인다.
//https://www.acmicpc.net/problem/1697


#include <stdio.h>
#include <queue>
#include <climits>
#include <tuple>
#pragma warning(disable:4996)

#define DPMAX 100001
using namespace std;
int dp[DPMAX];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < DPMAX; i++) {
		dp[i] = INT_MAX;
	}
	queue<int> que;
	que.push(n);
	dp[n] = 0;
	int now,move1,move2,move3;
	while (!que.empty()) {
		now = que.front();
		move1 = now - 1, move2 = now + 1, move3 = now * 2;
		if (move1 >= 0 && dp[now] + 1 < dp[move1]) {
			dp[move1] = dp[now] + 1;
			que.push(move1);
		}
		if (move2 < DPMAX && dp[now] + 1 < dp[move2]) {
			dp[move2] = dp[now] + 1;
			que.push(move2);
		}
		if (move3 < DPMAX && dp[now] + 1 < dp[move3]) {
			dp[move3] = dp[now] + 1;
			que.push(move3);
		}
		que.pop();
	}
	printf("%d", dp[k]);
}
