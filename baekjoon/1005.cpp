/*
*https://www.acmicpc.net/problem/1005
*어떤 노드에서 자신과 연결된 이전 노드들의 최대값+자기 자신의 값이 현재 노드까지 가능한 최소시간.
*목표 노드 번호가 주어지면 거꾸로 되돌아가면서 구하면 됨.
*/
#include <stdio.h>

bool graph[1000][1000];
int time[1000];
int dp[1000];

int T;
int N, K;
int calc(int x) {
	if (dp[x] != -1) 
		return dp[x];
	
	
	int max = -1;
	for (int i = 0; i < N; i++) {
		if (graph[i][x] == true) {
			int temp = calc(i);
			if (max < temp) {
				max = temp;
			}
		}
	}

	if (max == -1)
		dp[x] = time[x];
	else
		dp[x] = max + time[x];

	return dp[x];
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			graph[i][k] = 0;
		}
		dp[i] = -1;
	}

}
int main()
{
	scanf("%d", &T);
	int tx, ty, targ;
	for (int t = 0; t < T; t++) {
		
		scanf("%d %d", &N, &K);
		clear();
	
		for (int i = 0; i < N; i++) {
			scanf("%d", &time[i]);
		}
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &tx, &ty);
			graph[tx-1][ty-1] = true;
		}
		scanf("%d", &targ);
		printf("%d\n",calc(targ-1));
	}
}
