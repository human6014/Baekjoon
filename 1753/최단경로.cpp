#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int V, E;
int dist[20001];
vector<pair<int, int>> node[30001];

void Dijkstra(int start) {
	priority_queue <pair<int, int>,
			 vector<pair<int, int>>,
			greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ dist[start], start });

	int nowDist;
	int nowNode;
	while (!pq.empty()) {
		nowDist = pq.top().first;
		nowNode = pq.top().second;
		pq.pop();

		//if (dist[nowNode] > nowDist)continue;

		for (int i = 0; i < node[nowNode].size(); i++) {
			int newDist = node[nowNode][i].first;

			if (dist[newDist] > nowDist + node[nowNode][i].second) {
				dist[newDist] = nowDist + node[nowNode][i].second;
				pq.push(make_pair(dist[newDist], newDist));
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int startNode;
	cin >> V >> E;
	cin >> startNode;
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	int start, end, value;
	for (int i = 0; i < E; i++) {
		cin >> start >> end >> value;
		node[start].push_back({ end,value });
	}

	Dijkstra(startNode);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] <<"\n";
	}
}
/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

0	2	3	7	INF
*/