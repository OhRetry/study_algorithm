//BFS를 이용한 기본적인 시뮬레이션 문제. BFS의 최고 level이 정답이 된다.
//https://www.acmicpc.net/problem/7576

#include <stdio.h>
#include <queue>

using namespace std;
int n, m;
int arr[1000][1000];

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };
int simulation() {
	int result = 0;
	queue<pair<int,int>> que;
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			if (arr[i][k] == 1)
				que.push(make_pair(i, k));
		}
	}
	int nowy, nowx, nexty, nextx;
	while(!que.empty()){
		int que_size = que.size();
		result++;
		for(int t=0;t<que_size;t++) {			
			pair<int, int> now = que.front();
			nowy = now.first, nowx = now.second;
			for (int i = 0; i < 4; i++) {
				nexty = nowy + dy[i], nextx = nowx + dx[i];
				if (nexty >= 0 && nexty < m && nextx >= 0 && nextx < n) {
					if (arr[nexty][nextx] == 0) {
						arr[nexty][nextx] = 1;
						que.push(make_pair(nexty, nextx));
					}
				}
			}
			que.pop();
		}

	}
	if (result > 0)
		result--;
	bool isOK = true;
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			if (arr[i][k] == 0)
				isOK = false;
		}
	}
	if (isOK)
		return result;	
	else
		return -1;

}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			scanf("%d", &arr[i][k]);		
		}
	}
	printf("%d", simulation());
}
