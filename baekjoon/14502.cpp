/*
https://www.acmicpc.net/problem/14502

주어진 2차원 격자에서 1을 3개 넣는 조합을 만들고 각 조합에 대해 BFS/DFS를 이용해서 바이러스가 퍼지지 않는 최대 면적을 구하는 문제이다.
1.combination함수에서 조합을 만들고
2.calc함수에서 모든 바이러스 위치에 대해 BFS실시
n*m = s라고 하면 
combination은 sC3
2차원 격자에서의 탐색은 최대 s이기 때문에 calc에서 2중 for문 BFS탐색은 s의 시간복잡도를 갖는다.
따라서 시간복잡도
O(s) = sC3 * s
이다.

*/

#include <stdio.h>
#include <queue>

using namespace std;

int n, m, max = 0;
char arr[8][8];
bool visited[8][8];
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
void clear() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			visited[i][k] = false;
		}
	}
}
int BFS(int y,int x) {
	int cnt = 0;
	queue<pair<int, int>> que;
	que.push(make_pair(y, x));
	pair<int, int> now;
	int nowy, nowx, nexty,nextx;
	while (!que.empty()) {
		cnt++;
		now = que.front();
		nowy = now.first, nowx = now.second;
		for (int i = 0; i < 4; i++) {
			nexty = nowy + dy[i], nextx = nowx + dx[i];
			if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < m) {
				if (arr[nexty][nextx] != 1 && visited[nexty][nextx] == false) {
					visited[nexty][nextx] = true;
					que.push(make_pair(nexty, nextx));	
				}
			}
		}
		que.pop();
	}
	return cnt;
}
int calc() {
	int cnt_1 = 0,cnt_2 = 0;
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (arr[i][k] == 1) {
				cnt_1++;
			}
			else if (visited[i][k] == false && arr[i][k] == 2) {
				visited[i][k] = true;
				cnt_2 += BFS(i, k);
			}
		}
	}
	return n * m - cnt_1 - cnt_2;
}

int combination(int y,int x,int cnt) {
	int result = 0;
	if (cnt == 3) {
		clear();
		result = calc();
		return result;
	}
	int temp;
	for (int k = x; k < m; k++) {
		if (arr[y][k] == 0) {
			arr[y][k] = 1;
			temp = combination(y, k+1, cnt + 1);
			if (temp > result)
				result = temp;
			arr[y][k] = 0;
		}
	}
	for (int i = y+1; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (arr[i][k] == 0) {
				arr[i][k] = 1;
				temp = combination(i, k+1, cnt + 1);
				if (temp > result)
					result = temp;
				arr[i][k] = 0;
			}
		}
	}
	return result;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%d", &arr[i][k]);
		}
	}
	printf("%d", combination(0, 0, 0));
}
