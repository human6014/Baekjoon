#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M;
int dist[1001];
vector<pair<int, int>> nodes[1001];

int answerDistCount;
int answerNodes[1001];
int Dijkstra(int startNode,int endNode) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({dist[startNode] = 0,startNode});

	int frontDist,frontNode;
	int newDist, newNode;
	while (!pq.empty()) {
		frontDist = pq.top().first;
		frontNode = pq.top().second;
		pq.pop();

		if (frontNode == endNode) return frontDist;

		for (int i = 0; i < nodes[frontNode].size(); i++) {
			newNode = nodes[frontNode][i].first;
			newDist = nodes[frontNode][i].second;

			if (dist[newNode] > frontDist + newDist) {
				dist[newNode] = frontDist + newDist;
				answerNodes[newNode] = frontNode;
				pq.push({ dist[newNode] , newNode });
			}
		}
	}
	return -1;
}
int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i <= N; i++) {
		dist[i] = INT32_MAX;
	}
	int start, end, value;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> value;
		nodes[start].push_back({ end,value });
	}
	int startNode, endNode;
	vector<int>reverseNodes;
	cin >> startNode >> endNode;
	cout << Dijkstra(startNode, endNode) <<"\n";
	int node = endNode;
	while (node != 0) {
		reverseNodes.push_back(node);
		node = answerNodes[node];
	}
	cout << reverseNodes.size() << "\n";
	for (int i = reverseNodes.size() - 1; i >= 0; i--) {
		cout << reverseNodes[i] << " ";
	}
	
}