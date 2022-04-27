#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

/*
int N, M;
int node[1001][1001];
int dist[100001];
bool isVisited[1001];
int Dijkstra(int startNode, int endNode) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[startNode] = 0, startNode });

	int nowDist;
	int nowNode;
	while (!pq.empty()) {
		nowDist = pq.top().first;
		nowNode = pq.top().second;
		pq.pop();

		if (nowNode == endNode) return nowDist;
		if (isVisited[nowNode]) continue;
		isVisited[nowNode] = true;

		for (int i = 1; i <= N; i++) {
			if (dist[i] > node[nowNode][i] + dist[nowNode]) {
				dist[i] = node[nowNode][i] + dist[nowNode];
				pq.push({ dist[i], i });
			}
		}
	}
}
int main() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) node[i][j] = 0;
			else node[i][j] = INF;
		}
		dist[i] = INF;
	}
	int start, end, value;
	for (int i = 1; i <= M; i++) {
		cin >> start >> end >> value;
		if(node[start][end] > value) node[start][end] = value;
	}
	int startNode, endNode;
	cin >> startNode >> endNode;

	cout << Dijkstra(startNode, endNode);
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		cout << dist[i] << "\n";
	}
}
*/


int N, M;
vector<pair<int, int>> node[1001];
int dist[100001];
int Dijkstra(int startNode, int endNode) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[startNode] = 0, startNode });

	int nowDist;
	int nowNode;
	while (!pq.empty()) {
		nowDist = pq.top().first;
		nowNode = pq.top().second;
		pq.pop();

		if (nowNode == endNode) return nowDist;

		for (int i = 0; i < node[nowNode].size(); i++) {
			int newNode = node[nowNode][i].first;

			if (dist[newNode] > node[nowNode][i].second + nowDist) {
				dist[newNode] = node[nowNode][i].second + nowDist;
				pq.push({ dist[newNode], newNode });
			}
		}
	}
	return -1;
}
int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	int start, end, value;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> value;
		node[start].push_back({ end,value });
	}
	int startNode, endNode;
	cin >> startNode >> endNode;

	cout << Dijkstra(startNode, endNode);
}
/*
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

0	2	3	1	4
*/
