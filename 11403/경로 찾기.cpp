#include <iostream>
using namespace std;

int N;
bool node[101][101];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> node[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			if (i == k)continue;
			for (int j = 1; j <= N; j++) {
				if (node[i][k] == 1 && node[k][j]) node[i][j] = 1;
			}
		}
	}
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << node[i][j] <<" ";
		}
		cout << endl;
	}
}