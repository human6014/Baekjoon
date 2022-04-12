#include <iostream>

using namespace std;
const int INF = 10000001;
int W[101][101];
void floyd(int n)
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (W[i][k] + W[k][j] < W[i][j]) {
					W[i][j] = W[i][k] + W[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (W[i][j] == INF)cout << 0 << " ";
			else cout << W[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)W[i][j] = 0;
			else W[i][j] = INF;
		}
	}

	int first, second, value;
	for (int i = 1; i <= m; i++) {
		cin >> first >> second >> value;
		if (W[first][second] > value) W[first][second] = value;
	}
	floyd(n);
}