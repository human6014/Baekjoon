#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int vertex[101][101];
int isVisit[101][101];

int movePosition[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };


int newX, newY;
vector<int>Group;
int inGroupNum;
void Recursive(int x,int y) {
	if (vertex[x][y] == 0 || isVisit[x][y] == 1)return;
	isVisit[x][y] = 1;
	inGroupNum++;
	for (int i = 0; i < 4; i++) {
		newX = x + movePosition[i][0];
		newY = y + movePosition[i][1];
		if (newX <= 0 || newY <= 0 || newX > N || newY > N)continue;
		Recursive(newX, newY);
	}
}
void DFS() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (vertex[i][j] == 0 || isVisit[i][j] == 1) continue;
			Recursive(i,j);
			Group.push_back(inGroupNum);
			inGroupNum = 0;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &vertex[i][j]);
		}
	}
	DFS();
	sort(Group.begin(), Group.end());
	cout << Group.size() << "\n";
	for (int i = 0; i < Group.size(); i++) {
		cout << Group[i] << "\n";
	}
}