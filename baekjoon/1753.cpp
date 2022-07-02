/*
정점의 개수가 최대 20000개로 인접행렬로 표현한다면 20000^2개로 메모리 제한인 256MB를 초과한다.
문제에서 제시한 간선의 최대 개수는 300000개 이하이므로 인접리스트 방식으로 표현하는 것이 적절하다.
시간복잡도는 O(ElogV)
*/

#include <stdio.h>
#include <queue>
#include <climits>
#include <tuple>
#include <vector>

using namespace std;

int n, e;
vector<pair<int, int>> edge[20001];
int dist[20001];
void dijkstra(int x) {
	priority_queue<pair<int,int>> que;
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
	dist[x] = 0;
	que.push(make_pair(0, x));
	int now,to,w;
	while (!que.empty()) {
		now = que.top().second;
		for (auto iter = edge[now].begin(); iter != edge[now].end(); iter++) {
			to = (*iter).first;
			w = (*iter).second;
			if (dist[now] + w < dist[to]) {
				dist[to] = dist[now] + w;
				que.push(make_pair(-dist[to], to));
			}
		}		
		que.pop();
	}
}
int main() {
	int s;
	scanf("%d %d", &n, &e);
	scanf("%d", &s);
	
	int x, y, w;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[x].push_back(make_pair(y, w));
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INT_MAX) {
			printf("INF\n");
		}
		else {
			printf("%d\n",dist[i]);
		}
	}
}
